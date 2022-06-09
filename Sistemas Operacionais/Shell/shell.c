#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <strings.h>
#include <string.h>
#include <sys/stat.h>

int count_tk(int argc, char **argv, char *tk) {
	int i, count = 0;
	int token;
	for (i = 0; i < argc; i++) {
		token = strcmp(argv[i], tk);
		if (!token) {
			count += 1;
		}
	}
	return count;
}

int busca_posicao(int argc, char **argv, char *tk) {
	int i;
	int token;
	for (i = 0; i < argc; i++) {
		token = strcmp(argv[i], tk);
		if (!token) {
			return i;
		}
	}
	return -1;
}

int executa_comando(char **cmd) {
	int ret;
	pid_t p;

	p = fork();
	if (p == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (p == 0) {
		if (execvp(cmd[0], cmd) < 0) {
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}

	else {
		waitpid(-1, &ret, 0);
		if (ret != 0) {	// problema na execucao (false) //
			return 0;
		}
	}

	return 1;
}

void executa_pipe(int argc, char **argv) {
	pid_t p;
	int count, size, pos;
	int fd[2], i, ret;
	char **cmd;

	count = count_tk(argc, argv, "|");
	size = argc - 1;
	cmd = &argv[1];

	for (i = 0; i < count; i++) {
		pos = busca_posicao(size, cmd, "|");
		cmd[pos] = NULL;

		pipe(fd);

		p = fork();
		if (p == -1) {
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (p == 0) {
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
			if (execvp(cmd[0], cmd)) {
				perror("execvp");
				exit(EXIT_FAILURE);
			}
		}

		else {
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			cmd = &cmd[pos+1];
			size = size - (pos + 1);
			waitpid(-1, &ret, 0);
		}

	}

	if (execvp(cmd[0], cmd) < 0) {
		perror("execvp");
		exit(EXIT_FAILURE);
	}
}

void executa_condicionais(int argc, char **argv) {
	int size, status, count, i, tipo;
	int  pos_or, pos_and, *vet_cond;
	char **cmd;

	// conta a quantidade de condicionais //
	count = count_tk(argc, argv, "||");
	count += count_tk(argc, argv, "&&");

	cmd = &argv[1];
	size = argc - 1;

	for (i = 0; i <= count; i++) {

		pos_or = busca_posicao(size, cmd, "||");
		pos_and = busca_posicao(size, cmd, "&&");

		if ((pos_or < pos_and && pos_or != -1) || pos_and == -1) { // proxima condiconal é o OR //
			cmd[pos_or] = NULL;

			if ((tipo && status) || (!tipo && !status) || i == 0) {	// OR + ultimo comando nao executado //
				status = executa_comando(cmd);			// AND + ultimo comando executado //
				// atualiza status //
			}

			tipo = 0;
			cmd = &cmd[pos_or+1];
			size = size - (pos_or + 1);
		}

		else if ((pos_and < pos_or && pos_and != 1) ||  pos_or == -1) {	// proxima condicional é o AND //
			cmd[pos_and] = NULL;

			if ((tipo && status) || (!tipo && !status) || i == 0) {
				status = executa_comando(cmd);
			}

			tipo = 1;
			cmd = &cmd[pos_and+1];
			size = size - (pos_and + 1);
		}
	}
}

void executa_background(int argc, char **argv) {
	pid_t p, s;
	int ret;

	char **cmd;
	cmd = &argv[1];
	cmd[argc-2] = NULL; // posicao do & sempre no final do comando //

	p = fork();
	if (p == -1) {
		perror("fork");
	}

	if (p == 0) {
		s = setsid();
		if (s == -1) {
			perror("setsid");
			exit(EXIT_FAILURE);
		}
		else {
			if (execvp(cmd[0], cmd) < 0) {
				perror("execvp");
				exit(EXIT_FAILURE);
			}
		}
	}

	else {
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
		waitpid(-1, &ret, WNOHANG);
	}
}

int main(int argc, char **argv) {
	char **cmd;

	if (argc < 2) {
		perror("numero insuficiente de argumentos");
	}

	if (count_tk(argc,argv,"||") > 0 || count_tk(argc,argv,"&&") > 0) {
		executa_condicionais(argc, argv);
	}
	else if (count_tk(argc,argv,"|") > 0) {
		executa_pipe(argc, argv);
	}
	else if (count_tk(argc,argv,"&") > 0) {
		executa_background(argc, argv);
	}
	else {
		cmd = &argv[1];
		executa_comando(cmd);
	}

	return 0;
}


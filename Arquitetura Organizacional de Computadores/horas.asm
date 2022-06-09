	.data	
	
Msg1:	.asciiz "\n Entre com as horas: "
Erro1:	.asciiz "\n Valor inválido para as horas. Esperando um número entre 0 e 23"
Msg2:	.asciiz "\n Entre com os minutos: "
Erro2: 	.asciiz "\n Valor invalálido para os minutos. Esperando um número entre 0 e 59"
Msg3:	.asciiz "\n Entre com os segundos: "
Erro3:	.asciiz "\n Valor inválido para os segundos. Esperando um número entre 0 e 59"
Msg4:	.asciiz "\n Horário digitado: "
Msg5:	.asciiz ":"

	.text
	
horas: 	addi $v0, $zero, 4	# tipo de chamada exibição
	la $a0, Msg1		# mensagem 1
	syscall
	
	li $v0, 5		# chamada de leitura
	syscall
	add $s0, $v0, $zero	# salva o $v0 em $s0 - hora
	
	addi $t1, $zero, 23	# define $t1 como 23
	slt $t0, $t1, $s0 	# teste $s0 > 23
	bne $t0, $zero, erro_h	# se $s0 > 23 vai para erro_h
	
	slt $t0, $s0, $zero 	# teste $s0 < 0 e salva em $t0
	bne $t0, $zero, erro_h	# se $s0 < 0 vai para erro_h
		
	j min			# vai para min se estiver tudo certo
	
erro_h:	add $v0, $zero, 4	# tipo de chamada exibição
	la $a0, Erro1		# mensagem de erro 2
	syscall
		
	j horas			# volta para horas
		
min:	addi $v0, $zero, 4	# tipo de chamada exibição
	la $a0, Msg2		# mensagem 2
	syscall
	
	li $v0, 5		# chamada de leitura
	syscall
	add $s1, $v0, $zero	# salva o $v0 em $s1 - minutos
	
	addi $t1, $zero, 59	# define $t1 como 59
	slt $t0, $t1, $s1 	# teste $s1 > 59
	bne $t0, $zero, erro_m	# se $s1 > 59 vai para erro_m
	
	slt $t0, $s1, $zero 	# teste $s1 < 0 e salva em $t0
	bne $t0, $zero, erro_m	# se $s1 < 0 vai para erro_m
		
	j sec			# vai para sec se estiver tudo certo
	
erro_m: add $v0, $zero, 4	# tipo de chamada exibição
	la $a0, Erro2		# mensagem de erro 2
	syscall
		
	j min			# volta para min

sec:	addi $v0, $zero, 4	#tipo de chamada exibição
	la $a0, Msg3		#mensagem 3
	syscall
	
	li $v0, 5		#chamada de leitura
	syscall
	add $s2, $v0, $zero	#salva o $v0 em $s2 - segundos
	
	addi $t1, $zero, 59	# define $t1 como 59
	slt $t0, $t1, $s2 	# teste $s2 > 59
	bne $t0, $zero, erro_s	# se $s2 > 59 vai para erro_s
	
	slt $t0, $s2, $zero 	# teste $s2 < 0 e salva em $t0
	bne $t0, $zero, erro_s	# se $s2 < 0 vai para erro_s
		
	j imprime		# vai para imprime se estiver tudo certo

erro_s: add $v0, $zero, 4	# tipo de chamada exibição
	la $a0, Erro3		# mensagem de erro 3
	syscall
		
	j sec			# volta para sec
	
imprime:add $v0, $zero, 4	#tipo de chamada exibição
	la $a0, Msg4		#mensagem 4
	syscall
	
	li $v0, 1		#chamada de imprime inteiro
	add $a0, $zero, $s0	#armazena a hora
	syscall
	
	add $v0, $zero, 4	#tipo de chamada exibição
	la $a0, Msg5		#mensagem 5 -:
	syscall
	
	li $v0, 1		#chamada de imprime inteiro
	add $a0, $zero, $s1	#armazena os minutos
	syscall
	
	add $v0, $zero, 4	#tipo de chamada exibição
	la $a0, Msg5		#mensagem 5 -:
	syscall
	
	li $v0, 1		#chamada de imprime inteiro
	add $a0, $zero, $s2	#armazena os segundos
	syscall

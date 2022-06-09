seq_pareada = fastaread('seq_pareadas.txt');
size_seq = size(seq_pareada);
size_seq = size_seq(1);

file = fopen('resultados.txt', 'wt');

% Matriz de escores %
A = [5 -1 -2 -1 -3];
C = [-1 5 -3 -2 -4];
G = [-2 -3 5 -2 -2];
T = [-1 -2 -2 5 -1];
X = [-3 -4 -2 -1 0]; % - %

% define uma posicao (de 1 a 5) para cada nucleotideo
%            1   2   3   4   5 
position = ['A' 'C' 'G' 'T' '-'];

i = 1;
num_seq = 1; % variavel que auxilia na identifica??o das sequencias trabalhadas
while (i < size_seq)
    fprintf(file, 'Sequencia %d\n', num_seq);
    length_seq = length(seq_pareada(i).Sequence);
    sum_seq = sum(seq_pareada(i).Sequence == seq_pareada(i+1).Sequence); % soma da matriz de identidade
    valor_identidade = (sum_seq / length_seq) * 100;
   
    fprintf(file, 'Valor identidade = %.2f\n', valor_identidade);

    total_escore = 0;
    for j=1 : length_seq
        nuc_seq1 = seq_pareada(i).Sequence(j); % nucleotideo da sequencia .1
        nuc_seq2 = seq_pareada(i+1).Sequence(j); % nucleotideo da sequenia .2
       
        if (nuc_seq1 == 'A')
            vet_nuc = A; % vetor trabalhado na funcao escore referente ? sequencia .1
        elseif (nuc_seq1 == 'C')
            vet_nuc = C;
        elseif (nuc_seq1 == 'G')
            vet_nuc = G;
        elseif (nuc_seq1 == 'T')
            vet_nuc = T;
        else
            vet_nuc = X;
        end
        
        % porcura posicao do nucleotideo da sequencia .2 no vetor position
        pos = find(position == nuc_seq2); 
        total_escore = total_escore + vet_nuc(pos);  % incrementa o escore relativo ao vet_nuc
   
    end
    escore_medio = total_escore / length_seq;
    fprintf(file, 'Escore total = %d\n', total_escore);
    fprintf(file, 'Escore medio = %.2f\n', escore_medio);
   
    i = i + 2; % vai para a proxima sequencia, ignorando o i+1
    num_seq = num_seq + 1;
    fprintf(file, '%s\n', '------------------------');
end
fclose(file);

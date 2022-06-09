covid_fasta = fastaread('GCA_009858895.3_ASM985889v3_genomic.fna');
covid_sequence = covid_fasta.Sequence;
tamanho = length(covid_sequence);

A = 0;
T = 0;
C = 0;
G = 0;

for i=1:tamanho
    if (covid_sequence(i) == 'A')
        A = A + 1;
    elseif (covid_sequence(i) == 'T')
        T = T + 1;
    elseif (covid_sequence(i) == 'C')
        C = C + 1;
    else
        G = G + 1;
    end
end

resultados = fopen('resultados_covid.txt', 'wt');
fprintf(resultados, 'A = %d \n', A);
fprintf(resultados, 'T = %d \n', T);
fprintf(resultados, 'C = %d \n', C);
fprintf(resultados, 'G = %d \n', G);

fclose(resultados);

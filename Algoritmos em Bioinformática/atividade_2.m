inf = fastaread('influenza.txt');
tam_sequence = size(inf);

resultados = fopen('resultados_influenza.txt', 'wt');
fprintf(resultados, 'Numero de sequencias = %d \n\n', tam_sequence(1));

for i=1 : tam_sequence
    fprintf(resultados, '*************** Sequencia %d *************** \n', i);
    A = length(strfind(inf(i).Sequence, 'A'));
    T = length(strfind(inf(i).Sequence, 'T'));
    C = length(strfind(inf(i).Sequence, 'C'));
    G = length(strfind(inf(i).Sequence, 'G'));
    
    fprintf(resultados, 'A = %d \n', A);
    fprintf(resultados, 'T = %d \n', T);
    fprintf(resultados, 'C = %d \n', C);
    fprintf(resultados, 'G = %d \n', G);
    fprintf(resultados, 'Total de nucletideos = %d \n', A + T + G + C);
    
    conteudoAT = A + T;
    conteudoGC = C + G;
    tamanhoDNA = conteudoAT + conteudoGC;
    porcentagemGC = 100 * (conteudoGC / tamanhoDNA);
    fprintf(resultados, 'Conteudo GC = %d \n', conteudoGC);
    fprintf(resultados, 'Porcentagem AT = %f \n', porcentagemGC);
    temp_anelamento = 64.9 + 0.41 * porcentagemGC - (500/tamanhoDNA);
    fprintf(resultados, 'Temperatura de Anelamento = %f \n', temp_anelamento);
    fprintf(resultados, '\n');
    
    temperatura(i) = temp_anelamento;
    porcentagem(i) = porcentagemGC;
    
end

fclose(resultados);

figure
scatter(porcentagem,temperatura, 'd', 'MarkerEdgeColor', [0.6350 0.0780 0.1840], 'MarkerFaceColor', 'black', 'LineWidth', 4.5);
ylabel('Temperatura de Anelamento graus C');
xlabel('Counteudo GC %');
grid on


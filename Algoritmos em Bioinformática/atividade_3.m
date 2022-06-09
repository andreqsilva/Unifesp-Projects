reads = fastaread('reads.txt');
tam_reads = size(reads);

join = zeros(1,tam_reads(1)); % vetor para identificar união de sequencias
i = 1;
while (i <= tam_reads(1))
   
    if (join(i) == 1) % verifica se sequecia foi unida
        i = i + 1;
        continue;
    end

    exit = 0;	
    j = 1;
    while (j <= tam_reads(1))
       
        if (j == i | join(j) == 1)
            j =  j + 1;
            continue;
        end
       
        n = 1;
        while (n <= length(reads(i).Sequence)-3)
            four_1(1) = reads(i).Sequence(n);
            four_1(2) = reads(i).Sequence(n+1);
            four_1(3) = reads(i).Sequence(n+2);
            four_1(4) = reads(i).Sequence(n+3);
           
            t = 1;
            while (t <= length(reads(j).Sequence)-3)

                four_2(1) = reads(j).Sequence(t);
                four_2(2) = reads(j).Sequence(t+1);
                four_2(3) = reads(j).Sequence(t+2);
                four_2(4) = reads(j).Sequence(t+3);

                % soma a quantidade de nucleotídeos iguais
                count = sum(four_1 == four_2);
               
                if (count == 3)
                    t = t + 1;
                elseif (count == 2)
                    t = t + 2;
                elseif (count == 1)
                    t = t + 3;
                elseif (count == 0)
                    t = t + 4;  
                elseif (count == 4) % sequencias com 4 nucleotideos iguais
                   
                    if (n > t) % primeira sequencia mais à esquerda
                        if (length(reads(j).Sequence)+n > length(reads(i).Sequence))
                            reads(i).Sequence = [reads(i).Sequence(1:n-1) reads(j).Sequence]
                        end
                    else % segunda sequencia mais à esqueda
                        if (length(reads(i).Sequence)+t > length(reads(j).Sequence))
                            reads(i).Sequence = [reads(j).Sequence(1:t-1) reads(i).Sequence]
                        end
           
                    end
                    join(j) = 1;
                    exit = 1;
                    break;
                end
            end
             n = n + 1;
             if (exit == 1)
                break;
             end
        end
        if (exit == 1)
            break;
        end
        j = j + 1;
    end
    if (exit == 1)
        i = 1
    else
        i = i + 1;
    end
    fprintf('%s \n', reads(1).Sequence);
end

inf = fastaread('influenza.txt');
nSeg = size(inf);
nSeg = nSeg(1);

traducao = fopen('traducao.txt', 'wt');

for i=1 : nSeg
    %fprintf('sequence = %d ', i);
    %fprintf('%s \n', inf(i).Sequence(1:100));
    for frame = 1 : 3
        j = frame;
        fprintf(traducao, '>segmento %d frame %d\n', i, frame);
        %fprintf('frame = %d \n', frame);
        while (j < 100)
            if (j + 2) <= 100 
                codon(1) = inf(i).Sequence(j);
                codon(2) = inf(i).Sequence(j+1);
                codon(3) = inf(i).Sequence(j+2);
                seqAA = nt2aa(codon);
                %fprintf('%s %s \n', codon, seqAA)
                fprintf(traducao, '%s',seqAA);
            end
            j = j + 3;
        end
        fprintf(traducao, '\n');
    end 
end

fclose(traducao);
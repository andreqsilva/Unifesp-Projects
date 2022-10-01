seq1 = 'CGTGAATTCAT';
seq2 = 'GACTTAC';

qSeq1 = size(seq1);
qSeq2 = size(seq2);
qSeq1 = qSeq1(2);
qSeq2 = qSeq2(2);

M = zeros(qSeq2 + 1, qSeq1 + 1);
MArrows = zeros(qSeq2 + 1, qSeq1 + 1);
W = -4;
maxScore = 0;
nBestPos = 1;
bestPos = [];

for i=1 : qSeq2
    for j=1 : qSeq1    
        if seq1(j) == seq2(i)
            S = 5;
        elseif seq1(j) ~= seq2(i)
            S = -3;
        elseif seq1(j) == '-'
            S = -4;
        elseif seq2(i) == '-'
            S = -4;
        end
       
    diagonalArrow = M(i, j) + S;
    verticalArrow = M(i, j+1) + W;
    leftArrow = M(i+1, j) + W;
    maxValue = max(diagonalArrow, max(verticalArrow, max(leftArrow, 0)));
    M(i+1, j+1) = maxValue;
       
    if (maxValue == diagonalArrow)
        MArrows(i+1, j+1) = 1;
    elseif (maxValue == verticalArrow)
        MArrows(i+1, j+1) = 2;
    elseif (maxValue == leftArrow)
        MArrows(i+1, j+1) = 3;
    else
        MArrows(i+1, j+1) = -1;
    end
   
    if (maxValue > maxScore)
        maxScore = maxValue;
        nBestPos = 1;
        bestPos = [];
        bestPos(nBestPos, 1) = i+1;
        bestPos(nBestPos, 2) = j+1;
    elseif (maxValue == maxScore)
        nBestPos = nBestPos + 1;
        bestPos(nBestPos, 1) = i+1;
        bestPos(nBestPos, 2) = j+1;
    end
   
    end
end

M
MArrows

for i=1 : nBestPos
    totalScore = 0;
    posValue = -1;
    posI = bestPos(i, 1);
    posJ = bestPos(i, 2);
    alinhamentoA = '';
    alinhamentoB = '';
    while (posValue ~= 0)
        arrow = MArrows(posI, posJ);
        if (arrow == 1)
            alinhamentoA = strcat(alinhamentoA, seq2(posI-1));
            alinhamentoB = strcat(alinhamentoB, seq1(posJ-1));
            if (seq2(posI-1) == seq1(posJ-1))
                totalScore = totalScore + 5;
            else
                totalScore = totalScore - 3;
            end
            posI = posI-1;
            posJ = posJ-1;
        elseif (arrow == 2)
            alinhamentoA = strcat(alinhamentoA, seq2(posI-1));
            alinhamentoB = strcat(alinhamentoB, '-');
            posI = posI-1;
            posJ = posJ;
            totalScore = totalScore - 4;
        elseif (arrow == 3)
            alinhamentoA = strcat(alinhamentoA, seq2(posI-1));
            alinhamentoB = strcat(alinhamentoB, '-');
            posI = posI;
            posJ = posJ-1;
            totalScore = totalScore - 4;
        end
        posValue = M(posI, posJ);
    end
   
    % imprimir os resultados %
    for j=1 : length(alinhamentoA)
        fprintf('%c', alinhamentoA(j));
    end
    fprintf('\n');
    for j=1 : length(alinhamentoB)
        fprintf('|', alinhamentoB(j));
    end
    fprintf('\n');
    for j=1 : length(alinhamentoB)
        fprintf('%c', alinhamentoB(j));
    end
    
    fprintf('\n------------\n');
    fprintf('score = %d\n', totalScore);
    fprintf('------------\n');
   
end
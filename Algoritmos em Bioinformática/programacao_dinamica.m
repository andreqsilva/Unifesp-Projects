wMax = 13; % peso maximo da mochila
itens = [0 0; 5 5; 4 6; 7 8; 7 4]; % valor e peso de cada item
qItens = size(itens); % quantidade de itens
c = zeros(qItens(1), wMax+1); % gera uma matriz de zeros

for i=2 : qItens(1)
    vi = itens(i, 1);
    wi = itens(i, 2);
    for w=2 : wMax+1
        if (wi > w-1)
            c(i, w) = c(i-1, w);
        elseif (i > 1 && wi <= w-1)
            c(i, w) = max(vi + c(i-1, w-wi), c(i-1, w));
        end
    end
end

i = qItens(1);
k = wMax + 1;
qMochila = 1;
while (i > 1 && k > 1)
    wi = itens(i, 2);
    if c(i, k) ~= c(i-1, k)
        mochila(qMochila) = i;
        qMochila = qMochila + 1;
        i = i - 1;
        k = k - wi;
    else
        i = i -1;
    end
end
c
fprintf('SOLUCAO OTIMA:\n');
for i=1 : qMochila-1
   fprintf('item %d\n', mochila(i)-1); 
end
w = 0.70
c1 = 0.20
c2 = 0.60
r1 = 0.4657
r2 = 0.5319
n = int(input('Número de interações: '))

GBP = 0
GBF = 0
Pbest = []
for i in range(n):
    if i == 0:
        x = [[0.4657, 0.8956, 0.3877, 0.4902, 0.5039]]
        v = [[0.5319, 0.8185, 0.8331, 0.7677, 0.1708]]
        LBP = []
        tam = len(x[0])
        
        for j in range(tam):
            x[i][j] = round(10*(x[i][j]-0.5), 5)
            v[i][j] = round(v[i][j]-0.5, 5)
    
    else:
        y = []
        u = []
        for j in range(tam):
            y.append(round(v[i-1][j]*w + c1*r1*(Pbest[j] - x[i-1][j]) + c2*r2*(GBP - x[i-1][j]), 5))
            
        v.append(y)

        for j in range(tam):
            u.append(round(x[i-1][j] + v[i][j], 5))
        x.append(u)
    

    
    print('Interação', i+1)
    print('v(%d)' %(i+1), v[i])
    print('x(%d)' %(i+1), x[i])

    F = []
    for l in range(tam):
        F.append(round(1 + 2*x[i][l] - x[i][l]*x[i][l], 5))
    
    maior = max(F)
        
    if maior >= GBF:
        GBF = maior
        GBP = x[i][F.index(max(F))]
        Pbest = x[i]

    print('F(%d)'%(i+1), F)    
    print('Local best position – LBP (Pbest) =', Pbest)
    print('Global best fitness =', GBF)
    print('Global best position =', GBP)
    print()

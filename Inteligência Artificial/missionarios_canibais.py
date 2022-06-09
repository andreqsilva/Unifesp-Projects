def dfs_ida(grafo, vertice, visitados, fila, Q, ant, sequencia):
    
    while Q:
        vertice = Q.pop(0)
        if grafo[(vertice[0], vertice[1])] == []:
            del visitados[len(visitados)-1]
            del sequencia[len(sequencia)-1]
            
        elif (grafo[(vertice[0], vertice[1])][0] == ant) and len(grafo[vertice[0], vertice[1]]) == 1 and (grafo[vertice[0], vertice[1]]) not in visitados:
            del sequencia[len(sequencia)-1]

        for u in grafo[(vertice[0], vertice[1])]:
            if u not in visitados:
                    
                visitados.append(u)
                sequencia.append(u)
                Q.append(u)
                fila.append(u)
                dfs_ida(grafo, vertice, visitados, fila, Q, sequencia[len(visitados)-2], sequencia)
        
        if Q:
            del(fila[len(fila)-1])
            a = fila[len(fila)-1]
            Q = [a]
            dfs_ida(grafo, a, visitados, fila, Q, sequencia[len(visitados)-2], sequencia)
        
    return sequencia

def dfs_volta(grafo, vertice, visitados, fila, Q, fim, ant, sequencia):
    
    while Q:
        vertice = Q.pop(0)
        if grafo[(vertice[0], vertice[1])] == []:
            del visitados[len(visitados)-1]
            del sequencia[len(sequencia)-1]
            
        elif (grafo[(vertice[0], vertice[1])][0] == ant) and len(grafo[vertice[0], vertice[1]]) == 1 and (grafo[vertice[0], vertice[1]]) not in visitados and (grafo[vertice[0], vertice[1]][0]) != fim:
            del sequencia[len(sequencia)-1]
    
        for u in grafo[(vertice[0], vertice[1])]:
            if u not in visitados:
            
                visitados.append(u)
                Q.append(u)
                fila.append(u)
                sequencia.append(u)
                if u == fim:
                    return sequencia
                dfs_volta(grafo, vertice, visitados, fila, Q, fim, sequencia[len(visitados)-2], sequencia)
                
                
        
        if Q:
            del(fila[len(fila)-1])
            a = fila[len(fila)-1]
            Q = [a]
            dfs_volta(grafo, a, visitados, fila, Q, fim, sequencia[len(visitados)-2], sequencia)
            
    return sequencia

## gera um grafo com os estados viáveis ##

grafo = {}
esquerda = [3,3] ## começo com 3 canibais e 3 bebes em uma das margens ##
direita = [0,0]

bote = [[1,0], [0,1], [1,1], [2,0], [0,2]] ## condicoes possiveis no bote ##
vertice = []
v = []

visitados = [[3,3]]
Q = [0]
fila = [[3,3]]         

         
i = 0;
while fila:
    cont = 0
    v = []
    if(i%2==0):
        esquerda = fila.pop(0)
        direita = [(3-esquerda[0]), (3-esquerda[1])]
        
        for w in bote:
            a = 0
            c1 = esquerda[0] - w[0]
            b1 = esquerda[1] - w[1]
            c2 = direita[0] + w[0]
            b2 = direita[1] + w[1]
            
            
            if(c1 <= 3 and b1 <=3 and c2 <= 3 and b2 <= 3 and c1 >= 0 and c2 >= 0 and b1 >= 0 and b2 >= 0):
                if (b2 != 0):
                    if (c1 <= b1 and c2 <= b2):
                        v.append([c2,b2])
                        
                        if [c2,b2] not in visitados:
                            fila.append([c2,b2])
                            visitados.append([c2,b2])
            
                else:
                    if (c1 <= b1):
                        v.append([c2,b2])
                        if [c2,b2] not in visitados:
                            fila.append([c2,b2])
                            visitados.append([c2,b2])

        vertice.append(v)
        grafo.update({(esquerda[0],esquerda[1]):v})
        
    
    else:
        
        direita = fila.pop(0)
        esquerda = [(3-direita[0]), (3-direita[1])]
        
        for w in bote:
            a = 0
            c1 = esquerda[0] + w[0]
            b1 = esquerda[1] + w[1]
            c2 = direita[0] - w[0]
            b2 = direita[1] - w[1]

            if(c1 <= 3 and b1 <=3 and c2 <= 3 and b2 <= 3 and c1 >= 0 and c2 >= 0 and b1 >= 0 and b2 >= 0):

                if (b2 != 0):
                    if (c1 <= b1 and c2 <= b2):
                        v.append([c1,b1])
                        
                        if [c1,b1] not in visitados:
                            fila.append([c1,b1])
                            visitados.append([c1,b1])
                else:
                    if (c1 <= b1 and c1 + b1 != 0 and c2 + b2 != 0):
                        v.append([c1,b1])
                        
                        if [c1,b1] not in visitados:
                            fila.append([c1,b1])
                            visitados.append([c1,b1])
                        
        grafo.update({(direita[0],direita[1]):v})
        vertice.append(v)

    i += 1

visitados = [[3,3]] ## começo com 3 canibais e 3 bebes ##
Q = [[3,3]]
fila = [[3,3]]
ant = [[]]
sequencia = [[3,3]]

solucao = dfs_ida(grafo, vertice, visitados, fila, Q, ant, sequencia)
a = visitados[len(visitados)-1]
visitados = [a]
Q = [a]
fila = [a]
ant = [[]]

sequencia = [a]
solucao_volta = (dfs_volta(grafo, vertice, visitados, fila, Q, [3,3], ant, sequencia))
solucao_volta.pop(0)

solucao.extend(solucao_volta)

print('          C  B    Solução    C  B')
for i in range(len(solucao)):
    if (i%2==0) :
        print('esquerda', solucao[i], '--> ...', end=' ')
    else:
        print('<--', solucao[i], 'direita ')
print('FIM')


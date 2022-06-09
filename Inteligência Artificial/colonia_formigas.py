def funcao_prob(G,alpha,beta,qualidade,feromonio,vetor,visitados_indice,visitados_vetor,pos,fila):
    s = 0
    i = 0
    for q in qualidade[vetor]:
        if q != 0 and i not in visitados_indice:
            s = s + ((alpha*feromonio[vetor][i])*(beta*1/q))
        i += 1

    i = 0
    vet_prob = []
    for w in qualidade[vetor]:
        if w == 0 or i in visitados_indice:
            vet_prob.append(0)
        else:
            vet_prob.append(round(((alpha*feromonio[vetor][i])*(beta*1/w)) / s, 2))
            
        i += 1

    for chave, value in pos.items():
        if value == vet_prob.index(max(vet_prob)):
            a = chave
            break
        
    fila.append(a)


def atualiza_feromonio(G,rho,feromonio,qualidade):
    for keys in G.keys():
        i = 0
        for f in feromonio[keys]:
            if f != 0:
                t = round((1-rho)*f + rho*1/qualidade[keys][i], 2)
                feromonio[keys][i] = t

            i += 1


G = {'A': ['B', 'C', 'D', 'E'], 'B': ['A', 'C', 'D', 'E'], 'C': ['A', 'B', 'D', 'E'], 'D': ['A', 'B', 'C', 'E'], 'E': ['A', 'B', 'C', 'D']}

alpha = 1
beta = 1
rho = 0.5

qualidade = {'A':[0,2,10,8,3], 'B':[1,0,2,5,7], 'C':[9,1,0,3,6], 'D':[10,4,3,0,2], 'E':[2,7,5,1,0]}
feromonio = {'A':[0,2,2,2,2], 'B':[2,0,2,2,2], 'C':[2,2,0,2,2], 'D':[2,2,2,0,2], 'E':[2,2,2,2,0]}
pos = {'A':0, 'B':1, 'C':2, 'D':3, 'E':4}

i = 0
n = int(input('Número de interações: '))
while(i < n):
    
    fila = ['A'] ## começando do A ##
    visitados_vetor = []
    visitados_indice = []

    while fila:
        if fila[0] not in visitados_vetor:
            funcao_prob(G,alpha,beta,qualidade,feromonio,fila[0],visitados_indice,visitados_vetor,pos,fila) 
            visitados_vetor.append(fila[0])
            visitados_indice.append(pos[fila[0]])

        fila.pop(0)

    atualiza_feromonio(G,rho,feromonio,qualidade)

    ## imprime sequência ##
    print('--- Interação', i+1, '---')
    print('Percurso') 
    for v in range(len(visitados_vetor)):
        if v == (len(visitados_vetor) - 1):
            print(visitados_vetor[v])
        else:
            print(visitados_vetor[v], end=' -> ')
    print()    

    ## imprime tabela atualizada de feromônios ##
    print('Feromônio')
    for keys, value in feromonio.items():
        print(keys, value)
    print()
    
    i += 1
    

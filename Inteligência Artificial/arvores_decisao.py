import math
import random
import numpy as np
from sklearn.datasets import load_iris

## Arvore de decisao ##
iris = load_iris()

def prob_esquerda(corte,atributo,data_info): ## estuda o valor de corte para o filho da esquerda ##
  samples = 0
  classe = [0,0,0]
  data_filho = []
  for w in range(len(iris.data)):
    if w not in data_info:
      continue
    else:
      if iris.data[w][atributo] <= corte:
        data_filho.append(w)
        samples += 1
        if iris.target[w] == 0:
          classe[0] += 1
        elif iris.target[w] == 1:
          classe[1] += 1
        else:
          classe[2] += 1
          
  value = [classe[0], classe[1], classe[2]]
  probabilidade = [p/samples for p in classe if p]
  return probabilidade,samples,data_filho,value

def prob_direita(corte,atributo,data_info): ## estuda o valor de corte para o filho da direita ##
  samples = 0
  classe = [0,0,0]
  data_filho = []
  for w in range(len(iris.data)):
    if w not in data_info:
      continue
    else:
      if iris.data[w][atributo] > corte:
        data_filho.append(w)
        samples += 1
        if iris.target[w] == 0:
          classe[0] += 1
        elif iris.target[w] == 1:
          classe[1] += 1
        else:
          classe[2] += 1
  
  value = [classe[0], classe[1], classe[2]]
  probabilidade = [p/samples for p in classe if p]
  return probabilidade,samples,data_filho,value

def entropia(probabilidades): ## calculo da entropia ##
  return sum(-p * math.log(p,2) for p in probabilidades if p)

def ganho_informacao(entropia_pai,entropia_esq,entropia_dir,n_pai,n_esq,n_dir): ## ganho de informacao ##
  peso1 = n_esq/n_pai
  peso2 = n_dir/n_pai
  return entropia_pai - (peso1*entropia_esq  + peso2*entropia_dir)

def buid_tree(info,data_filho,u,t,info_data,atributo,X_train,y_train): ## constrói a arvore de decisao ##
  P = []
  I = []
  for w in range(4):
    v = []
    indice = []
    i = 0
    for i in y_train:
      if i not in data_filho:
        continue
      else:
        v.append(iris.data[i][w])
        indice.append(iris.target[i])

    k = 0
    while k < (len(v)-1):
      l = k+1
      while l < (len(v)):
        if v[k] >= v[l]:
          aux = v[k]
          v[k] = v[l]
          v[l] = aux

          aux = indice[k]
          indice[k] = indice[k]
          indice[k] = aux
        l += 1
      k += 1

    media = (v[indice.index(indice[0]+1)-1] + v[indice.index(indice[0]+1)]) / 2
    P.append(media)
    probabilidades_esq,n_esq,data_esq,value_esq = prob_esquerda(P[w],w,data_filho)
    probabilidades_dir,n_dir,data_dir,value_dir = prob_direita(P[w],w,data_filho)

    n_pai = info[u][1]
    entropia_pai = info[u][0] 
    entropia_esq = entropia(probabilidades_esq)
    entropia_dir = entropia(probabilidades_dir)
  
    I.append(ganho_informacao(entropia_pai,entropia_esq,entropia_dir,n_pai,n_esq,n_dir))

    info[t+1] = [entropia_esq,n_esq,value_esq,value_esq.index(max(value_esq))]
    info[t+2] = [entropia_dir,n_dir,value_dir,value_dir.index(max(value_dir))]

    info_data[t+1] = data_esq
    info_data[t+2] = data_dir

  atributo[u] = [I.index(max(I)),P[I.index(max(I))]]

def cria_grafo(lista_de_vertices, lista_de_arestas):
    grafo = {}
    for vertice in lista_de_vertices:
        grafo[vertice] = []
    for aresta in lista_de_arestas:
        grafo[aresta[0]].append(aresta[1])
    return grafo

def decisao(grafo,vertice,visitados,fila,Q,dados,atributo,info,profundidade,classe):
  while Q:
    vertice = Q.pop(0)
    
    if info[vertice][0] == 0.0:
      classe.append(info[vertice][3])
      
    elif profundidade == 4:
      classe.append(info[vertice][3])

    for u in grafo[vertice]:
      if dados[atributo[vertice][0]] <= atributo[vertice][1]:
        visitados.append(u)
        Q.append(u)
        fila.append(u)
        profundidade += 1
        decisao(grafo,vertice,visitados,fila,Q,dados,atributo,info,profundidade,classe)
      
      else:
        visitados.append(grafo[vertice][1])
        Q.append(grafo[vertice][1])
        fila.append(grafo[vertice][1])
        profundidade += 1
        decisao(grafo,vertice,visitados,fila,Q,dados,atributo,info,profundidade,classe)
        
      if Q:
        del(fila[len(fila)-1])
        a = fila[len(fila)-1]
        Q = [a]
        decisao(grafo,a,visitados,fila,Q,dados,atributo,info,profundidade,classe)

  return visitados

def train_test_dados(data,tam_treino,total):
    y_train = []
    x_train = []
    y_test = []
    x_test = []
    
    y_train = random.sample(range(0, total), tam_treino)
    y_train.sort()
    for w in y_train:
        x_train.append(data[w])

    for j in range(total):
      if j not in y_train:
        y_test.append(j)
        x_test.append(data[j])

    return x_train, y_train, x_test, y_test

def accuracy(classification,target):
  total = 0
  acertos = 0
  for i in range(len(classification)):
    if classification[i] == -1:
      continue
    else:
      if classification[i] == target[i]:
        acertos += 1
      total += 1
    
  return acertos/total

tamData = len(iris.data)
porcentagem_treino = 0.7 # porcentagem de treino
tamTreino = int(tamData*porcentagem_treino)

X_train, y_train, X_test, y_test = train_test_dados(iris.data,tamTreino,tamData)
if porcentagem_treino == 1:
  X_test, y_test = X_train, y_train

print('Conjunto treino:',y_train)
print('Conjunto teste:', y_test)
print()

target = [0,0,0]
for i in y_train:
  if iris.target[i] == 0:
    target[0] += 1
  elif iris.target[i] == 1:
    target[1] += 1
  else:
    target[2] += 1
    
prob_raiz = [target[0]/len(y_train),target[1]/len(y_train),target[2]/len(y_train)]
entropia_raiz = sum(-p * math.log(p,2) for p in prob_raiz if p)
info = {0:[entropia_raiz,len(y_train),[target[0],target[1],target[2]], target.index(max(target))]} ## no raiz ##
vertices = [0]
arestas = []
info_data = {}
atributo = {}
profundidade_no = 5

u = 0
tam = 0
while u < profundidade_no:
  if u == 0:
    data_filho = y_train
    buid_tree(info,data_filho,u,tam,info_data,atributo,X_train,y_train)
  elif info[u][0] == 0.0:
    u += 1
    continue
  else:
    buid_tree(info,info_data[u],u,tam,info_data,atributo,X_train,y_train)
  
  arestas.append((u,tam+1))
  arestas.append((u,tam+2))
  vertices.append(tam+1)
  vertices.append(tam+2)
  tam += 2

  u += 1
grafo = cria_grafo(vertices, arestas)

classification = []
for i in range(len(iris.data)):
  if i not in y_test:
    classification.append(-1)
    continue
  else:
    visitados = [0]
    Q = [0] 
    fila = [0]
    vertice = []
    profundidade = 0
    classe = []

    decisao(grafo,vertice,visitados,fila,Q,iris.data[i],atributo,info,profundidade,classe)
    classification.append(classe[0])

j = 0
for i in range(len(classification)):
  if classification[i] == -1:
    continue
  else:
    print(y_test[j], '-', iris.target_names[classification[i]])
    j += 1

print()
print("Acurácia:", accuracy(classification,iris.target))

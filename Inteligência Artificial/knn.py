import math
import random
import numpy as np
from sklearn.datasets import load_iris

## KNN ##

iris = load_iris()
iris.keys()

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

def euclidean_distance(atributos1,atributos2):
  sub = []
  qua = []
  for i in range(len(atributos1)):
    sub.append(atributos1[i] - atributos2[i]) # subtração 
    qua.append(sub[i]*sub[i]) # quadrado

  euclidean = math.sqrt(sum(qua))
  return euclidean

def knn_classification(indices,target):
  classification = []
  for i in indices:
    if i == -1:
      classification.append(-1)
      continue
    else:
      v = [0,0,0]
      for j in i:
        if target[j] == 0:
          v[0] += 1
        elif target[j] == 1:
          v[1] += 1
        else:
          v[2] += 1
      classification.append(v.index(max(v)))
  
  return classification

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
print('Conjunto treino:',y_train)
print('Conjunto teste:', y_test)
print()

matriz = []
for i in range(tamData):
  vet = []
  for j in range(tamData):
    vet.append(-1)
  matriz.append(vet)

for i in y_test:
  atributos1 = iris.data[i]
  for j in y_train:
      atributos2 = iris.data[j]
      matriz[i][j] = euclidean_distance(iris.data[i],iris.data[j])

## Procura os k vizinhos mais proximos ##
indices = []
mat = []
tamL = len(matriz)
k = 3 # k vizinhos

for i in range(tamL):
  if i not in y_test:
    mat.append(-1)
    indices.append(-1)
    continue
  else:
    vet = []
    vet2 = []
    tamVet = 0
    for a in range(tamL):
      if a == i or matriz[i][a] == -1:
        continue
      else:
        num = matriz[i][a] 
        if tamVet < k:
          vet.append(num)
          vet2.append(a)
          tamVet += 1
        else:
          j = 0
          while j < k:
            if num < vet[j]:
              aux = vet[j]
              vet.remove(aux)
              vet.append(num)
              aux2 = vet2[j]
              vet2.remove(aux2)
              vet2.append(a)
                                  
              l = 0
              b = aux2
              while (l < k):
                if aux < vet[l]:
                  aux2 = vet[l]
                  vet.remove(aux2)
                  vet.append(aux)
                  aux = aux2
                  c = vet2[l]
                  vet2.remove(c)
                  vet2.append(b)
                  b = c

                l += 1
              j = k
            else:
              j += 1
                
    mat.append(vet)
    indices.append(vet2)

classification = knn_classification(indices,iris.target)
print('k =',k)
j = 0
for i in range(len(classification)):
  if classification[i] == -1:
    continue
  else:
    print(y_test[j], '-', iris.target_names[classification[i]])
    j += 1

print()
print("Acurácia:", accuracy(classification,iris.target))

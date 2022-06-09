import math
import random
import numpy as np
from sklearn.datasets import load_iris

## Naive Bayes ##

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

def media_desvio(dados_treino):
  ind1 = [0,50,100]
  ind2 = [50,100,150]

  ## calcula a media de cada coluna/atributo ##
  media_classe = []
  for i in range(3):
    media = []
    for j in range(4):
      v = []
      for data in dados_treino[ind1[i]:ind2[i]]:
        v.append(data[j])
      media.append(np.mean(v))
    media_classe.append(media)

  ## calcula o desvio padrao ##
  desvio_classe = []
  for i in range(3):
    desvio = []
    for j in range(4):
      v = []
      for data in dados_treino[ind1[i]:ind2[i]]:
        v.append(data[j])
      desvio.append(np.std(v))
    desvio_classe.append(desvio)

  return media_classe, desvio_classe

def gaussian(x, mean, std): 
    expoente = math.exp (- ((x - mean) ** 2 / (2 * std ** 2))) 
    return (1 / (math.sqrt (2 * math.pi) * std)) * expoente

def predict(dados_teste,y_test):
  classification = []
  for w in range(150):
    if w not in y_test:
      classification.append(-1)
      continue
    else:
      P = []
      for i in range(3):
        p = []
        for j in range(4):
          p.append(gaussian(dados_teste[w][j],media_classe[i][j],desvio_classe[i][j]))

        mult = 1
        for k in p:
          mult *= k
      
        P.append(mult)

      Prob = []
      for l in range(3):
        Prob.append(P[l] / sum(P))
      classification.append(Prob.index(max(Prob)))

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

media_classe, desvio_classe = media_desvio(X_train)
classification = predict(iris.data,y_test)

j = 0
for i in range(len(classification)):
  if classification[i] == -1:
    continue
  else:
    print(y_test[j], '-', iris.target_names[classification[i]])
    j += 1

print()
print("Acurácia:", accuracy(classification,iris.target))


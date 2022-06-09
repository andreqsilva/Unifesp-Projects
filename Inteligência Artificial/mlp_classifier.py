import numpy as np
import pandas as pd
from sklearn.neural_network import MLPClassifier ## https://scikit-learn.org/stable/modules/generated/sklearn.neural_network.MLPClassifier.html ##
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report, confusion_matrix

## https://www.kaggle.com/uciml/glass ##
df = pd.read_csv('glass.csv')

features = df.columns[:-1].tolist()
X = df[features] 
y = df['Type']

random_state = 7 # randonização #
test_size = 0.3 # porcentagem teste #
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = test_size , random_state = random_state)

# verbose True - visualizar as mensagens do console -> conseguimos ver a funcao de erro diminuindo -> quando a variação da melhora de erro é muito baixa por 10 epocas consecutivas, o treinamento para
# hidden_layer_sizes - define o número de camadas e o número de nós -> utilizei 2 camadas // para o número de neurônios, utilizei a fórmula (numero de entradas + numero de saidas) / 2 -> (9+7)/2 = 8
# max_iter - número máximo de interações
# random_state - randonização 
MLP = MLPClassifier(verbose=True, hidden_layer_sizes=(8,7), max_iter=10000, random_state=1)

MLP.fit(X_train,y_train)
glass_classification = MLP.predict(X_test)
print()
print(confusion_matrix(y_test,glass_classification))
print(classification_report(y_test,glass_classification))

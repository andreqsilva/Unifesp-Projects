def funcao_corrige(s1,s2): ## procura as letras em comum ##
    intersect = 0
    h1 = len(s1)
    h2 = len(s2)
    if h1 > h2:
        intersect = len(list(filter(lambda s: s in s1, s2)))
        _max = h1

    else:
        intersect = len(list(filter(lambda s: s in s2, s1)))
        _max = h2
        
    return _max - intersect ## retorna a diferença entra letras em comum e a palavra de maior tamanho ##


vocabulary = []
words = []
t = int(input())

for i in range(t):
    palavra = input()
    vocabulary.append(palavra)

a = int(input())
i = 0
len_vocabulary = len(vocabulary)

while i < a:
    palavra = input()
    add_palavras = [palavra]*len_vocabulary
    A = list(map(funcao_corrige, add_palavras, vocabulary))
    similarity_value = min(A)
    similarity_word = vocabulary[A.index(similarity_value)]

    if similarity_value == 0 and palavra == similarity_word:
        print(palavra, 'is correct')

    else:
        if similarity_value <= 1:
            print(palavra, 'is a misspelling of', similarity_word)
        else:
            print(palavra, 'is unknown')

    i += 1

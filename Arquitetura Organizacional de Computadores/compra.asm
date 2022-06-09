.data 
	msgProduto: 	.asciiz "\nDigite o nome do produto: "
	msgValor: 	.asciiz "Insita o valor unitário deste produto: "
	msgQuantidade: 	.asciiz "Insira a quantidade desejada deste produto: "
	msgPedido:	.asciiz "\nPedido:"
	msgValorUni:	.asciiz	"Valor unitário: "
	msgTotalProd:	.asciiz "\nValor total do produto: "
	doisPontos:	.asciiz	":"
	vezes:		.asciiz "x "
	msgComprarMais:	.asciiz "\nDeseja comprar algo a mais? Se sim, digite 1. Caso contrário, digite 0. Resposta: "
	msgTotal:	.asciiz	"\n\nValor total do pedido: "
	pulaLinha: 	.asciiz "\n"
	
	nomeProduto_1: .space 50
	nomeProduto_2: .space 50
	nomeProduto_3: .space 50
	nomeProduto_4: .space 50
	nomeProduto_5: .space 50
	
	zero: .float 0.0
.text
   ### compra de produtos ###
   produto_1:
   	## $t3 vai ser um contador ##
   	addi $t3, $t3, 1    # $t3 = 1 / 1 produto na "sacola"
   	
  	## imprime msgProduto ##
	li $v0, 4
	la $a0, msgProduto
	syscall
	
	## leitura nomeProduto_1 ##
	li $v0, 8
	la $a0, nomeProduto_1
	la $a1, 25
	syscall
	
	# imprime msgValor ##
	li $v0, 4
	la $a0, msgValor
	syscall
	
	## leitura valor float ##
	li $v0, 6
	syscall
	lwc1 $f1, zero 
	add.s $f3, $f0, $f1	# salvando valor em $f3
	
	# imprime msgQuantidade
	li $v0, 4
	la $a0, msgQuantidade
	syscall
	
	li $v0, 5	
	syscall
	add $s1, $v0, $zero  	# salva quantidade em $s1
	
	#########
	li $v0, 4
	la $a0, msgComprarMais
	syscall
	
	li $v0, 5	
	syscall
	add $s0, $v0, $zero  	# salva em $s0 a decisão do usuário [0/1]
	bne $s0, $zero, produto_2    # vai para o proximo produto da compra se a resposta  for 1
	
	j imprime_1

   produto_2:
   	addi $t3, $t3, 1    # +1 / $t3 = 2 / 2 produtos na "sacola" 	
   	
   	# imprime msgProduto
	li $v0, 4
	la $a0, msgProduto
	syscall
	
	# leitura nomeProduto_2
	li $v0, 8
	la $a0, nomeProduto_2
	la $a1, 25
	syscall
	
	# imprime msgValor
	li $v0, 4
	la $a0, msgValor
	syscall
	
	# leitura valor float
	li $v0, 6
	syscall 
	add.s $f5, $f0, $f1	# salvando valor em $f5
	
	# imprime msgQuantidade
	li $v0, 4
	la $a0, msgQuantidade
	syscall
	
	li $v0, 5	
	syscall
	add $s2, $v0, $zero  	# salva quantidade em $s2
	
	#########
	li $v0, 4
	la $a0, msgComprarMais
	syscall
	
	li $v0, 5	
	syscall
	add $s0, $v0, $zero  	# salva em $s0 a decisão do usuário [0/1]
	bne $s0, $zero, produto_3    # vai para o proximo produto da compra se a resposta  for 1
	
	j imprime_1
	
   produto_3:
   	addi $t3, $t3, 1    # +1 / $t3 = 3 / 3 produtos na "sacola" 	
   	
   	# imprime msgProduto
	li $v0, 4
	la $a0, msgProduto
	syscall
	
	# leitura nomeProduto_2
	li $v0, 8
	la $a0, nomeProduto_3
	la $a1, 25
	syscall
	
	# imprime msgValor
	li $v0, 4
	la $a0, msgValor
	syscall
	
	# leitura valor float
	li $v0, 6
	syscall 
	add.s $f7, $f0, $f1	# salvando valor em $f7
	
	# imprime msgQuantidade
	li $v0, 4
	la $a0, msgQuantidade
	syscall
	
	li $v0, 5	
	syscall
	add $s3, $v0, $zero  	# salva quantidade em $3
	
	#########
	li $v0, 4
	la $a0, msgComprarMais
	syscall
	
	li $v0, 5	
	syscall
	add $s0, $v0, $zero  	# salva em $s0 a decisão do usuário [0/1]
	bne $s0, $zero, produto_4    # vai para o proximo produto da compra se a resposta  for 1
	
	j imprime_1   	
	
   produto_4:
   	addi $t3, $t3, 1    # +1 / $t3 = 4 / 4 produtos na "sacola" 	
   	
   	# imprime msgProduto
	li $v0, 4
	la $a0, msgProduto
	syscall
	
	# leitura nomeProduto_2
	li $v0, 8
	la $a0, nomeProduto_4
	la $a1, 25
	syscall
	
	# imprime msgValor
	li $v0, 4
	la $a0, msgValor
	syscall
	
	# leitura valor float
	li $v0, 6
	syscall 
	add.s $f9, $f0, $f1	# salvando valor em $f9
	
	# imprime msgQuantidade
	li $v0, 4
	la $a0, msgQuantidade
	syscall
	
	li $v0, 5	
	syscall
	add $s4, $v0, $zero  	# salva quantidade em $s4
	
	#########
	li $v0, 4
	la $a0, msgComprarMais
	syscall
	
	li $v0, 5	
	syscall
	add $s0, $v0, $zero  	# salva em $s0 a decisão do usuário [0/1]
	bne $s0, $zero, produto_5    # vai para o proximo produto da compra se a resposta  for 1
	
	j imprime_1

   produto_5:
   	addi $t3, $t3, 1    # +1 / $t3 = 5 / 5 produtos na "sacola" 	
   	
   	# imprime msgProduto
	li $v0, 4
	la $a0, msgProduto
	syscall
	
	# leitura nomeProduto_2
	li $v0, 8
	la $a0, nomeProduto_5
	la $a1, 25
	syscall
	
	# imprime msgValor
	li $v0, 4
	la $a0, msgValor
	syscall
	
	# leitura valor float
	li $v0, 6
	syscall 
	add.s $f11, $f0, $f1	# salvando valor em $f11
	
	# imprime msgQuantidade
	li $v0, 4
	la $a0, msgQuantidade
	syscall
	
	li $v0, 5	
	syscall
	add $s5, $v0, $zero  	# salva quantidade em $s5
	
	j imprime_1
	
   #### funções imprime ####
   imprime_1:
   	## pula linha ##
	li $v0, 4
	la $a0, pulaLinha
	syscall
   	
   	## imprimindo quantidade ##
   	li $v0, 1		
	add $a0, $zero, $s1	
	syscall
	
	## imprimindo "x" ##
	li $v0, 4
	la $a0, vezes
	syscall
	
	## imprimindo nome do produto ##
	li $v0, 4
	la $a0, nomeProduto_1
	syscall
	
	## imprimindo o valor unitário ##
	li $v0, 4
	la $a0, msgValorUni
	syscall
	
	add.s $f12, $f1, $f3	
	
	li $v0, 2
	syscall

   loop1:
   	addi $t4, $t4, 1
    	bgt $t4, $s1, imprime_1Exit
    	add.s $f13, $f13, $f3 	# adciona o valor unitario $s1 vezes e salva em $f13
    	j loop1
   
   imprime_1Exit:
	## imprimindo total do produto ##
	li $v0, 4
	la $a0, msgTotalProd
	syscall
	
	add.s $f12, $f1, $f13	
	li $v0, 2
	syscall
	
	## implementando o preço total da compra ##
	add.s $f23, $f13, $f1	# $f23 = valor total da compra
	
	## subtrai contador ##
	sub $t3, $t3, 1 	# subtraindo 1 do contador
   	beq $t3, $zero, total 	# se for igual a zero, é porque já imprimiu todos os produtos e vai para total
   	
   imprime_2:
   	## pula linha ##
	li $v0, 4
	la $a0, pulaLinha
	syscall
	
	## pula linha ##
	li $v0, 4
	la $a0, pulaLinha
	syscall
   	
   	## imprimindo quantidade ##
   	li $v0, 1		
	add $a0, $zero, $s2	
	syscall
	
	## imprimindo "x" ##
	li $v0, 4
	la $a0, vezes
	syscall
	
	## imprimindo nome do produto ##
	li $v0, 4
	la $a0, nomeProduto_2
	syscall
	
	## imprimindo o valor unitário ##
	li $v0, 4
	la $a0, msgValorUni
	syscall
	
	lwc1 $f1, zero
	add.s $f12, $f1, $f5	
	
	li $v0, 2
	syscall
	
	add $t4, $zero, $zero	# reseta $t4
	
   loop2:
   	addi $t4, $t4, 1
    	bgt $t4, $s2, imprime_2Exit
    	add.s $f15, $f15, $f5 	# adciona o valor unitario $s2 vezes e salva em $f15
    	j loop2
   
   imprime_2Exit:
	## imprimindo total do produto ##
	li $v0, 4
	la $a0, msgTotalProd
	syscall
	
	add.s $f12, $f1, $f15
	li $v0, 2
	syscall
	
	## implementando o preço total da compra ##
	add.s $f23, $f23, $f15	
	
	## subtrai contador ##
	sub $t3, $t3, 1 	# subtraindo 1 do contador
   	beq $t3, $zero, total 	
   	

   imprime_3:
   	## pula linha ##
	li $v0, 4
	la $a0, pulaLinha
	syscall
	
	## pula linha ##
	li $v0, 4
	la $a0, pulaLinha
	syscall
   	
   	## imprimindo quantidade ##
   	li $v0, 1		
	add $a0, $zero, $s3	
	syscall
	
	## imprimindo "x" ##
	li $v0, 4
	la $a0, vezes
	syscall
	
	## imprimindo nome do produto ##
	li $v0, 4
	la $a0, nomeProduto_3
	syscall
	
	## imprimindo o valor unitário ##
	li $v0, 4
	la $a0, msgValorUni
	syscall
	
	lwc1 $f1, zero
	add.s $f12, $f1, $f7	
	
	li $v0, 2
	syscall
	
	add $t4, $zero, $zero	# reseta $t4
	
   loop3:
   	addi $t4, $t4, 1
    	bgt $t4, $s3, imprime_3Exit
    	add.s $f17, $f17, $f7 	# adciona o valor unitario $s3 vezes e salva em $f17
    	j loop3
   
   imprime_3Exit:
	
	## imprimindo total do produto ##
	li $v0, 4
	la $a0, msgTotalProd
	syscall
	
	add.s $f12, $f1, $f17
	li $v0, 2
	syscall
	
	## implementando o preço total da compra ##
	add.s $f23, $f23, $f17	
	
	## subtrai contador ##
	sub $t3, $t3, 1 	# subtraindo 1 do contador
   	beq $t3, $zero, total
   
    imprime_4:
   	## pula linha ##
	li $v0, 4
	la $a0, pulaLinha
	syscall
	
	## pula linha ##
	li $v0, 4
	la $a0, pulaLinha
	syscall
   	
   	## imprimindo quantidade ##
   	li $v0, 1		
	add $a0, $zero, $s4	
	syscall
	
	## imprimindo "x" ##
	li $v0, 4
	la $a0, vezes
	syscall
	
	## imprimindo nome do produto ##
	li $v0, 4
	la $a0, nomeProduto_4
	syscall
	
	## imprimindo o valor unitário ##
	li $v0, 4
	la $a0, msgValorUni
	syscall
	
	lwc1 $f1, zero
	add.s $f12, $f1, $f9	
	
	li $v0, 2
	syscall
	
	add $t4, $zero, $zero	# reseta $t4
	
   loop4:
   	addi $t4, $t4, 1
    	bgt $t4, $s4, imprime_4Exit
    	add.s $f19, $f19, $f9 	# adciona o valor unitario $s4 vezes e salva em $f19
    	j loop4
   
   imprime_4Exit:
	## imprimindo total do produto ##
	li $v0, 4
	la $a0, msgTotalProd
	syscall
	
	add.s $f12, $f1, $f19
	li $v0, 2
	syscall
	
	## implementando o preço total da compra ##
	add.s $f23, $f23, $f19	
	
	## subtrai contador ##
	sub $t3, $t3, 1 	# subtraindo 1 do contador
   	beq $t3, $zero, total
   	
   imprime_5:
   	## pula linha ##
	li $v0, 4
	la $a0, pulaLinha
	syscall
	
	## pula linha ##
	li $v0, 4
	la $a0, pulaLinha
	syscall
   	
   	## imprimindo quantidade ##
   	li $v0, 1		
	add $a0, $zero, $s5	
	syscall
	
	## imprimindo "x" ##
	li $v0, 4
	la $a0, vezes
	syscall
	
	## imprimindo nome do produto ##
	li $v0, 4
	la $a0, nomeProduto_5
	syscall
	
	## imprimindo o valor unitário ##
	li $v0, 4
	la $a0, msgValorUni
	syscall
	
	lwc1 $f1, zero
	add.s $f12, $f1, $f11	
	
	li $v0, 2
	syscall
	
	add $t4, $zero, $zero	# reseta $t4
	
   loop5:
   	addi $t4, $t4, 1
    	bgt $t4, $s5, imprime_5Exit
    	add.s $f21, $f21, $f11 	# adciona o valor unitario $s5 vezes e salva em $f21
    	j loop5
   
   imprime_5Exit:
	## imprimindo total do produto ##
	li $v0, 4
	la $a0, msgTotalProd
	syscall
	
	add.s $f12, $f1, $f21
	li $v0, 2
	syscall
	
	## implementando o preço total da compra ##
	add.s $f23, $f23, $f21	
		
   # imprime valor total do pedido	
   total:
   	li $v0, 4
	la $a0, msgTotal
	syscall

   	add.s $f12, $f1, $f23
	li $v0, 2
	syscall
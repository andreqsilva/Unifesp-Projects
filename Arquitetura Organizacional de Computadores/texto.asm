# Não consegui pensa em uma lógica pras palavras repetidas :/

.data

msg1: 	.asciiz "Número total de caracteres: "
msg2:	.asciiz "\nNúmero total de palavras: "
buffer: .space 128

.text

   main:
	addi $t2, $zero, 32  	# define $t3 como 32 = espaço
	li $v0, 8		# chamada de leitura
        la $a0, buffer		
        la $a1, 128	
        syscall
        
   loop:
        lb $t1, 0($a0) 		# carregar o conteudo do endereço $a0
        beq $t1, $zero, imprime # vai para imprime se caractere nulo
        beq $t1, $t2, palavra	# vai para palavras se $t1 = $t2 = 32 = espaço
        
        addi $t3, $t3, 1 	# adciona 1 -> letra
        addi $a0, $a0, 1 	# vai para o proximo byte    

        j loop 

   palavra:
    	addi $t0, $t0, 1     	# adciona 1 -> palavra
    	addi $t3, $t3, 1 	# adciona 1 -> letra
	addi $a0, $a0, 1        # vai para o proximo byte             
	j loop

   imprime:
   	add $v0, $zero, 4	# tipo de chamada exibição
	la $a0, msg1		# msg1
	syscall
   			
    	li $v0, 1		# imprime int
        move $a0, $t3 		# copia o valor de $t0
        syscall
        
        add $v0, $zero, 4	# tipo de chamada exibição
	la $a0, msg2		# msg2
	syscall
        
        li $v0, 1		# imprime int
        move $a0, $t0 		# copia o valor de $t3
        syscall

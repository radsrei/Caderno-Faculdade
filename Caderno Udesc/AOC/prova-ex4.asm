	.text
	.globl main
main:
	beqz $zero,loop
	
	j end
	
loop

	ori $v0,$zero,5
	syscall 
	ori $a0,$v0, 0
	syscall 
	ori $a1,$v0, 0
	syscall
	ori $a2,$v0,0
	
	beq $a0,1,soma
	beq $a0,2,subt
	beq $a0,3,multi
	beq $a0,4,divi
	beq $a0,5,end
	
	ori $v0,$zero,1
	syscall
	j loop
	
soma:
	ori $v0,$a1,$a0
	jr $ra
subt:
	sub $v0,$a1,$a2
	jr $ra
multi:
	mul $v0,$a1,$a2
	jr $ra
divi:
	div $a1,$a2
	mflo $v0
	jr $ra
end:
	li $vo, 10
	syscall 
	.text
	.globl main
main:
	ori $v0,$zero,5
	syscall 
	ori $a0,$v0, 0
	syscall 
	ori $a1,$v0, 0
	jal euclides
	
	ori $v0,$zero,1
	syscall
	j end
	
euclides:
	stl $t0,$a1,$a0
	bne $t0,$zero troca
	beqz $a0, bpol
	beqz $a1, apol
	
	
troca:
	ori $t1, $a0, 0
	move $a0, $a1
	move $a1, $t1
	jr $ra
bpol:
	ori $a1,$v0,0
	ori $v0,$zero,1
	syscall
	j end
apol:
	ori $a0,$v0, 0
	ori $v0,$zero,1
	syscall
	j end
end:
	li $vo, 10
	syscall 
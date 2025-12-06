 # Compilers MIPS code - 2025 FALL

.data    

_L0: .asciiz	"enter X"
_L1: .asciiz	" x is "

.align 2    

x:	.space	4  # GLOBAL VARIABLE

.text    

.globl main   

main:			# START OF FUNCTION

	subu $a0, $sp, 8		# set up $a0 to be the new spot for the SP
	sw $sp, 4($a0)		# remember old SP
	sw $ra, ($a0)		# remember current return address
	move $sp, $a0		# set the SP to the new value
	move $fp, $sp		# copy SP into $fp


	li $v0, 4		# print a string
	la $a0, _L0		# print string  location
	syscall		# perform write string


	la $a0, x		#  GLOBAL variable
	li $v0, 5		# read a VAR from input
	syscall		# perform read VAR
	sw $v0, ($a0)		# store the read into the memory address

	li $v0, 4		# print a string
	la $a0, _L1		# print string  location
	syscall		# perform write string


	la $a0, x		#  GLOBAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	li $v0, 1		# print NUMBER location
	syscall		# perform write NUMBER


	lw $ra, ($fp)		# reset return address
	lw $sp, 4($fp)		# reset SP
	li $v0, 10		# leave main function
	syscall		# only for ending main

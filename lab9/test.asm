 # Compilers MIPS code - 2025 FALL

.data    

_L0: .asciiz	"inside f"
_L1: .asciiz	"\n"
_L2: .asciiz	"Pick a number: "
_L3: .asciiz	"Wow! "
_L4: .asciiz	" is my fav number!"
_L5: .asciiz	"\n"
_L6: .asciiz	"\n"
_L7: .asciiz	"\n"
_L8: .asciiz	"\n"
_L9: .asciiz	"\n"
_L10: .asciiz	"\n"
_L11: .asciiz	"\n"
_L12: .asciiz	"A is true"
_L13: .asciiz	"\n"
_L14: .asciiz	"while loop test"
_L15: .asciiz	"\n"
_L16: .asciiz	"starting with number..."
_L17: .asciiz	"\n"
_L18: .asciiz	"\n"

.align 2    

x4:	.space	400  # GLOBAL VARIABLE

.text    

.globl main   

f:			# START OF FUNCTION

	subu $a0, $sp, 12		# set up $a0 to be the new spot for the SP
	sw $sp, 4($a0)		# remember old SP
	sw $ra, ($a0)		# remember current return address
	move $sp, $a0		# set the SP to the new value
	move $fp, $sp		# copy SP into $fp

	lw $t0, 4($fp)		# save old SP in $t0 for parameter handling
	lw $a0, 8($t0)		# load argument from caller
	sw $a0, 8($fp)		# store into parameter


	li $v0, 4		# print a string
	la $a0, _L0		# print string  location
	syscall		# perform write string


	addu $a0, $fp, 8		#  LOCAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	li $v0, 1		# print NUMBER location
	syscall		# perform write NUMBER


	addu $a0, $fp, 8		#  LOCAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	move $v0, $a0		# set return value
	lw $ra, ($sp)		# restore return address
	lw $sp, 4($sp)		# restore SP
	jr $ra		# return

	lw $ra, ($fp)		# reset return address
	lw $sp, 4($fp)		# reset SP
	jr $ra		# return to caller
main:			# START OF FUNCTION

	subu $a0, $sp, 88		# set up $a0 to be the new spot for the SP
	sw $sp, 4($a0)		# remember old SP
	sw $ra, ($a0)		# remember current return address
	move $sp, $a0		# set the SP to the new value
	move $fp, $sp		# copy SP into $fp


	addu $a0, $fp, 8		#  LOCAL variable
	subu $sp, $sp, 4		# push variable address
	sw $a0, ($sp)		# store variable address
	li $a0, 2		# is a constant
	subu $sp, $sp, 4		# push argument
	sw $a0, ($sp)		# store argument
	jal f		# call function
	addu $sp, $sp, 4		# remove aruments from stack
	move $a0, $v0		# get return value

	move $a1, $a0		# save expression result
	lw $a0, ($sp)		# load variable address
	addu $sp, $sp, 4		# pop stack
	sw $a1, ($a0)		# store value to variable

	addu $a0, $fp, 8		#  LOCAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	li $v0, 1		# print NUMBER location
	syscall		# perform write NUMBER


	li $v0, 4		# print a string
	la $a0, _L1		# print string  location
	syscall		# perform write string


	li $v0, 4		# print a string
	la $a0, _L2		# print string  location
	syscall		# perform write string


	addu $a0, $fp, 12		#  LOCAL variable
	li $v0, 5		# read a VAR from input
	syscall		# perform read VAR
	sw $v0, ($a0)		# store the read into the memory address

	li $v0, 4		# print a string
	la $a0, _L3		# print string  location
	syscall		# perform write string


	addu $a0, $fp, 12		#  LOCAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	li $v0, 1		# print NUMBER location
	syscall		# perform write NUMBER


	li $v0, 4		# print a string
	la $a0, _L4		# print string  location
	syscall		# perform write string


	li $v0, 4		# print a string
	la $a0, _L5		# print string  location
	syscall		# perform write string


	addu $a0, $fp, 24		#  LOCAL variable
	subu $sp, $sp, 4		# push variable address
	sw $a0, ($sp)		# store variable address
	li $a0, 1		# is a constant
	move $a1, $a0		# save expression result
	lw $a0, ($sp)		# load variable address
	addu $sp, $sp, 4		# pop stack
	sw $a1, ($a0)		# store value to variable

	addu $a0, $fp, 20		#  LOCAL variable
	subu $sp, $sp, 4		# push variable address
	sw $a0, ($sp)		# store variable address
	li $a0, 0		# is a constant
	move $a1, $a0		# save expression result
	lw $a0, ($sp)		# load variable address
	addu $sp, $sp, 4		# pop stack
	sw $a1, ($a0)		# store value to variable

	addu $a0, $fp, 24		#  LOCAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	li $v0, 1		# print NUMBER location
	syscall		# perform write NUMBER


	li $v0, 4		# print a string
	la $a0, _L6		# print string  location
	syscall		# perform write string


	addu $a0, $fp, 20		#  LOCAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	li $v0, 1		# print NUMBER location
	syscall		# perform write NUMBER


	li $v0, 4		# print a string
	la $a0, _L7		# print string  location
	syscall		# perform write string


	addu $a0, $fp, 16		#  LOCAL variable
	subu $sp, $sp, 4		# push variable address
	sw $a0, ($sp)		# store variable address
	addu $a0, $fp, 24		#  LOCAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	seq $a0, $a0, 0		# NOT operation
	move $a1, $a0		# save expression result
	lw $a0, ($sp)		# load variable address
	addu $sp, $sp, 4		# pop stack
	sw $a1, ($a0)		# store value to variable

	addu $a0, $fp, 16		#  LOCAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	li $v0, 1		# print NUMBER location
	syscall		# perform write NUMBER


	li $v0, 4		# print a string
	la $a0, _L8		# print string  location
	syscall		# perform write string


	addu $a0, $fp, 16		#  LOCAL variable
	subu $sp, $sp, 4		# push variable address
	sw $a0, ($sp)		# store variable address
	addu $a0, $fp, 20		#  LOCAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	seq $a0, $a0, 0		# NOT operation
	move $a1, $a0		# save expression result
	lw $a0, ($sp)		# load variable address
	addu $sp, $sp, 4		# pop stack
	sw $a1, ($a0)		# store value to variable

	addu $a0, $fp, 16		#  LOCAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	li $v0, 1		# print NUMBER location
	syscall		# perform write NUMBER


	li $v0, 4		# print a string
	la $a0, _L9		# print string  location
	syscall		# perform write string


	addu $a0, $fp, 16		#  LOCAL variable
	subu $sp, $sp, 4		# push variable address
	sw $a0, ($sp)		# store variable address
	addu $a0, $fp, 24		#  LOCAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	subu $sp, $sp, 4		# push left side on stack
	sw $a0, ($sp)		# store left side on stack
	addu $a0, $fp, 20		#  LOCAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	lw $a1, ($sp)		# load left side from stack
	addu $sp, $sp, 4		# pop stack
	and $a0, $a1, $a0		# EXPR: AND operation
	move $a1, $a0		# save expression result
	lw $a0, ($sp)		# load variable address
	addu $sp, $sp, 4		# pop stack
	sw $a1, ($a0)		# store value to variable

	addu $a0, $fp, 16		#  LOCAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	li $v0, 1		# print NUMBER location
	syscall		# perform write NUMBER


	li $v0, 4		# print a string
	la $a0, _L10		# print string  location
	syscall		# perform write string


	addu $a0, $fp, 16		#  LOCAL variable
	subu $sp, $sp, 4		# push variable address
	sw $a0, ($sp)		# store variable address
	addu $a0, $fp, 24		#  LOCAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	subu $sp, $sp, 4		# push left side on stack
	sw $a0, ($sp)		# store left side on stack
	addu $a0, $fp, 20		#  LOCAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	lw $a1, ($sp)		# load left side from stack
	addu $sp, $sp, 4		# pop stack
	or $a0, $a1, $a0		# EXPR: OR operation
	move $a1, $a0		# save expression result
	lw $a0, ($sp)		# load variable address
	addu $sp, $sp, 4		# pop stack
	sw $a1, ($a0)		# store value to variable

	addu $a0, $fp, 16		#  LOCAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	li $v0, 1		# print NUMBER location
	syscall		# perform write NUMBER


	li $v0, 4		# print a string
	la $a0, _L11		# print string  location
	syscall		# perform write string


	addu $a0, $fp, 24		#  LOCAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	beq $a0, 0, _L20		# IF: branch to END if condition is false

	li $v0, 4		# print a string
	la $a0, _L12		# print string  location
	syscall		# perform write string


_L20:			# ENDIF, if-then

	li $v0, 4		# print a string
	la $a0, _L13		# print string  location
	syscall		# perform write string


	li $v0, 4		# print a string
	la $a0, _L14		# print string  location
	syscall		# perform write string


	li $v0, 4		# print a string
	la $a0, _L15		# print string  location
	syscall		# perform write string


	li $v0, 4		# print a string
	la $a0, _L16		# print string  location
	syscall		# perform write string


	addu $a0, $fp, 28		#  LOCAL variable
	subu $sp, $sp, 4		# push variable address
	sw $a0, ($sp)		# store variable address
	li $a0, 5		# is a constant
	move $a1, $a0		# save expression result
	lw $a0, ($sp)		# load variable address
	addu $sp, $sp, 4		# pop stack
	sw $a1, ($a0)		# store value to variable

	addu $a0, $fp, 28		#  LOCAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	li $v0, 1		# print NUMBER location
	syscall		# perform write NUMBER


	li $v0, 4		# print a string
	la $a0, _L17		# print string  location
	syscall		# perform write string


_L21:			# WHILE loop start

	addu $a0, $fp, 28		#  LOCAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	subu $sp, $sp, 4		# push left side on stack
	sw $a0, ($sp)		# store left side on stack
	li $a0, 0		# is a constant
	lw $a1, ($sp)		# load left side from stack
	addu $sp, $sp, 4		# pop stack
	sgt $a0, $a1, $a0		# EXPR: GREATER THAN operation
	beq $a0, 0, _L22		# exit loop if condition is false

	addu $a0, $fp, 28		#  LOCAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	li $v0, 1		# print NUMBER location
	syscall		# perform write NUMBER


	addu $a0, $fp, 28		#  LOCAL variable
	subu $sp, $sp, 4		# push variable address
	sw $a0, ($sp)		# store variable address
	addu $a0, $fp, 28		#  LOCAL variable
	lw $a0, ($a0)		#  is a VARIABLE, get value
	subu $sp, $sp, 4		# push left side on stack
	sw $a0, ($sp)		# store left side on stack
	li $a0, 1		# is a constant
	lw $a1, ($sp)		# load left side from stack
	addu $sp, $sp, 4		# pop stack
	sub $a0, $a1, $a0		# EXPR: SUBTRACT operation
	move $a1, $a0		# save expression result
	lw $a0, ($sp)		# load variable address
	addu $sp, $sp, 4		# pop stack
	sw $a1, ($a0)		# store value to variable

	li $v0, 4		# print a string
	la $a0, _L18		# print string  location
	syscall		# perform write string


	j _L21		# jump back to loop start

_L22:			# WHILE loop end

	lw $ra, ($fp)		# reset return address
	lw $sp, 4($fp)		# reset SP
	li $v0, 10		# leave main function
	syscall		# only for ending main

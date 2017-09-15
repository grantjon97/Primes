/*
* Primes
* Jonathan Grant
* This program will find all prime numbers from 0 to 100,000
* and print them out in a formatted style.
*/

	     .section .data

prompt:      .ascii "\nPrime Numbers program\n\n"
	     .ascii "Below is a list of all prime numbers\n"
             .ascii "in the range 0 to 100,000.\n"
 	     .asciz "Note that 1 is not prime, and 2 is prime.\n\n"

test: .asciz "The Number: %d           "

# primeSpace explanation:
# 12,500 bytes = 100,000 bits, which is
# enough to find all prime numbers
# between 0 and 100,000.

primeSpace:  .zero 12500
endSpace:    .zero 1

/* Macros */

prints: .macro a, b

	# a - Print format
	# b - address of variable to print

	movq \a, %rdi
	movq \b, %rsi
	xorq %rax, %rax
	call printf

	.endm

	     .section .text

	     .global main

main:

	# Print the instructions
	prints $prompt, $0

	leaq primeSpace, %r15      # Load address of primeSpace into %r15
	leaq endSpace, %r9	   # Load ending address into %r9
	call crossOutEvens	   # Cross out even numbers
	leaq primeSpace, %r15	   # Put the beginning adress back into %r15
	orq $1, (%r15)		   # Make the number 1 not prime


	ret

forRange:

	# Examine every bit in primeSpace

	# See if the bit is set. If it is, go to the next bit
	andb %r13b, (%r15)
	jnz nextBit

	# Now we know that the bit is prime, so we must
	# set it along with it's odd multiples.


nextBit:

	# Decrement %r14 for countdown for loop
	decq %r14
	jnz forRange

exit:

	leaq test, %rdi
	movq (%r15), %rsi
	xorq %rax, %rax
	call printf

	ret

crossOutEvens:

	cmpq %r15, %r9
	je crossOutEvensExit

	#movq $0xAAAAAAAA, %r14
	#movq %r14, (%r15)
	addq $8, %r15
	jmp crossOutEvens

crossOutEvensExit:

	ret

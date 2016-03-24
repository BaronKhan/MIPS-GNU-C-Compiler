# Language Processors 2015 CW - bak14

--- 

## Description

This is a partial C to MIPS assembly compiler.

It currently supports the following:

- integer type variables
- all assignments and expressions
- basic control flow (if, while, for loop)
- function calls (max. 4 arguments)
- global variables
- integer arrays

It does not currently support the following:

- string or floating point type variables
- data structures
- advanced control flow (switch, goto)
- dynamic memory allocation
- unary or post-fix expressions
## Usage

Use the makefile to create the compiler using `make bin/c_compiler` and input C code into `stdin`. This will produce a stream of MIPS assembly code which can be compiled using the MIPS GCC toolchain. The input should be C90 and the output is MIPSIV.
## Testing

Run the shell script in the `test` folder to view the output of all C files in the `test/output` folder.
## Example

If the following C code is the input:

	#include <stdio.h>
	
	int f_add(int a, int b);
	int double_n(int n);
	int result;
	
	int main() {
		int x, y[20], i;
		x = f_add(4,2);
		y[10] = x;
		result = double_n(x);
		for (i=0; i < 6; i+=1) {
			x = i;
		}
		result += y[x+5];
		return result;
	}
	
	int f_add(int a, int b) {
		return a+b;
	}
	
	int double_n(int n) {
		return n*n;
	}

The MIPS assembly output will be:

		.section .mdebug.abi32
		.previous
		.abicalls
		.text
		.align  2
		.globl  main
		.set    nomips16
		.ent    main
		.type	main, @function
	main:
		.frame  $fp,120,$31
		.mask   0x40000000,-4
		.fmask  0x00000000,0
		.set    noreorder
		.set    nomacro
		addiu   $sp,$sp,-120
		sw      $fp,116($sp)
		move    $fp,$sp
		li      $4,4
		li      $5,2
		sw      $31,108($sp)
		.option pic0
		jal     f_add
		nop
	
		.option pic2
		lw      $31,108($sp)
		sw      $2,20($fp)
		move    $2,$0
		li      $2,10
		move    $9,$2
		lw      $2,20($fp)
		addu    $fp,$fp,$9
		sw      $2,24($fp)
		subu    $fp,$fp,$9
		lw      $2,20($fp)
		move    $4,$2
		sw      $31,108($sp)
		.option pic0
		jal     double_n
		nop
	
		.option pic2
		lw      $31,108($sp)
		sw      $2,12($fp)
		move    $2,$0
		li      $2,0
		sw      $2,104($fp)
		b       $L2
		nop
	
	$L3:
		lw      $2,104($fp)
		sw      $2,20($fp)
		lw      $7,104($fp)
		li      $2,1
		sw      $2,104($fp)
		addu    $2,$7,$2
		sw      $2,104($fp)
	$L2:
		lw      $2,104($fp)
		slt     $2,$2,6
		andi    $2,$2,0x00ff
		li      $3,0
		bne     $2,$3,$L3
		nop
	
		lw      $7,12($fp)
		lw      $2,20($fp)
		addi    $2,$2,5
		move    $8,$2
		addu    $fp,$fp,$8
		lw      $2,24($fp)
		subu    $fp,$fp,$8
		sw      $2,12($fp)
		addu    $2,$7,$2
		sw      $2,12($fp)
		lw      $2,12($fp)
		move    $sp,$fp
		lw      $fp,116($sp)
		addiu   $sp,$sp,120
		j       $31
		nop
	
		.set    macro
		.set    reorder
		.end    main
		.size   main, .-main
		.align  2
		.globl  f_add
		.set    nomips16
		.ent    f_add
		.type	f_add, @function
	f_add:
		.frame  $fp,152,$31
		.mask   0x40000000,-4
		.fmask  0x00000000,0
		.set    noreorder
		.set    nomacro
		addiu   $sp,$sp,-152
		sw      $fp,148($sp)
		move    $fp,$sp
		sw      $4,132($fp)
		sw      $5,136($fp)
		lw      $2,132($fp)
		lw      $3,136($fp)
		add     $2,$2,$3
		move    $sp,$fp
		lw      $fp,148($sp)
		addiu   $sp,$sp,152
		j       $31
		nop
	
		.set    macro
		.set    reorder
		.end    f_add
		.size   f_add, .-f_add
		.align  2
		.globl  double_n
		.set    nomips16
		.ent    double_n
		.type	double_n, @function
	double_n:
		.frame  $fp,184,$31
		.mask   0x40000000,-4
		.fmask  0x00000000,0
		.set    noreorder
		.set    nomacro
		addiu   $sp,$sp,-184
		sw      $fp,180($sp)
		move    $fp,$sp
		sw      $4,164($fp)
		lw      $2,164($fp)
		lw      $3,164($fp)
		mul     $2,$2,$3		# mult, mflo
		move    $sp,$fp
		lw      $fp,180($sp)
		addiu   $sp,$sp,184
		j       $31
		nop
	
		.set    macro
		.set    reorder
		.end    double_n
		.size   double_n, .-double_n
	


This MIPS assembly can then be compiled and linked using the MIPS GNU GCC toolchain.
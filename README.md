# Language Processors 2015 CW - bak14

--- 

## Description

This is a work-in-progress C90 to MIPS compiler. Currently the compiler only produces the MIPS assembly code for function bodies and can only evaluate integer arithmetic expressions, `+, -, *, /`.
## Usage

Use the makefile to create the code generator and input C code into stdin. This will produce a stream of MIPS assembly code which can be compiled using the MIPS GCC toolchain.

For instance, if the following C code is the input:

    int function(int a, int b) {
	    int x = 5 + 3;
	    int y;
	    y = (a + b) * x;
	    return y;
	}

The MIPS assembly output will be:

		.text
		.globl  function
		.ent    function
	function:
		.frame  $fp,24,$31
		.mask   0x40000000,-4
		.fmask  0x00000000,0
		.set    noreorder
		.set    nomacro
		addiu   $sp,$sp,-24
		sw      $fp,20($sp)
		move    $fp,$sp
		sw      $4,20($fp)
		sw      $5,24($fp)
		li      $2,8
		sw      $2,8($fp)
		move    $2,$0
		lw      $2,20($fp)
		lw      $3,24($fp)
		addu    $2,$2,$3
		lw      $3,8($fp)
		mul     $2,$2,$3		# mult, mflo
		sw      $2,12($fp)
		move    $2,$0
		lw      $2,12($fp)
		move    $sp,$fp
		lw      $fp,20($sp)
		addiu   $sp,$sp,24
		j       $31
		nop
	
		.set    macro
		.set    reorder
		.end    function
		.size   function, .-function




## Testing

Run the shell script in the test/c_codegen folder to view the output of all C files in the results folder.
	.text
	.globl  divide2
	.ent    divide2
divide2:
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
	lw      $2,20($fp)
	lw      $3,24($fp)
	teq     $3,$0,7		# div by 0 exception handler, 7=int div
	div     $2,$3
	mfhi    $2
	mflo    $2
	move    $sp,$fp
	lw      $fp,20($sp)
	addiu   $sp,$sp,24
	j       $31
	nop

	.set    macro
	.set    reorder
	.end    divide2
	.size   divide2, .-divide2

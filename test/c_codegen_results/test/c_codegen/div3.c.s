	.text
	.globl  divide3
	.ent    divide3
divide3:
	.frame  $fp,24,$31
	.mask   0x40000000,-4
	.fmask  0x00000000,0
	.set    noreorder
	.set    nomacro
	addiu   $sp,$sp,-24
	sw      $fp,20($sp)
	move    $fp,$sp
	li      $2,5
	sw      $2,8($fp)
	lw      $2,8($fp)
	li      $3,5
	teq     $3,$0,7		# div by 0 exception handler, 7=int div
	div     $2,$3
	mfhi    $2
	mflo    $2
	sw      $2,12($fp)
	move    $2,$0
	move    $sp,$fp
	lw      $fp,20($sp)
	addiu   $sp,$sp,24
	j       $31
	nop

	.set    macro
	.set    reorder
	.end    divide3
	.size   divide3, .-divide3

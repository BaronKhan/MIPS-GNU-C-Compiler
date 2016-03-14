	.text
	.globl  main
	.ent    main
main:
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
	li      $2,5
	sw      $2,12($fp)
	lw      $2,8($fp)
	lw      $3,12($fp)
	mul     $2,$2,$3		# mult, mflo
	move    $sp,$fp
	lw      $fp,20($sp)
	addiu   $sp,$sp,24
	j       $31
	nop

	.set    macro
	.set    reorder
	.end    main
	.size   main, .-main

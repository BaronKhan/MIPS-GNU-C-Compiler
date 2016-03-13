main:
	.frame  $fp,24,$31
	.mask   0x40000000,-4
	.fmask  0x00000000,0
	.set    noreorder
	.set    nomacro
	addiu   $sp,$sp,-24
	sw      $fp,20($sp)
	move    $fp,$sp
	li      $2,1
	sw      $2,8($fp)
	li      $2,4
	sw      $2,8($fp)
	move    $2,$0
	lw      $2,8($fp)
	addiu   $2,$2,5
	addi    $sp,$sp,4
	sw      $2,0($sp)		# save $2 onto stack
	lw      $2,8($fp)
	addiu   $2,$2,2
	move    $3,$2
	lw      $2,0($sp)
	addi    $sp,$sp,-4
	addu    $2,$2,$3
	sw      $2,8($fp)
	move    $2,$0
	move    $sp,$fp
	lw      $fp,20($sp)
	addiu   $sp,$sp,24
	j       $31
	nop

	.set    macro
	.set    reorder
	.end    main
	.size   main, .-main

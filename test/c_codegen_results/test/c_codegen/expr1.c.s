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
	li      $2,1
	sw      $2,8($fp)
	lw      $2,8($fp)
	addiu   $2,$2,2
	addi    $sp,$sp,4
	sw      $2,0($sp)		# save $2 onto stack
	lw      $3,8($fp)
	li      $2,3
	subu    $2,$2,$3
	move    $3,$2
	lw      $2,0($sp)
	addi    $sp,$sp,-4
	subu    $2,$2,$3
	addiu   $2,$2,1
	sw      $2,12($fp)
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

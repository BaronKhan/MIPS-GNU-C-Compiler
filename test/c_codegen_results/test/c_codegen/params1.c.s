	.text
	.globl  func
	.ent    func
func:
	.frame  $fp,24,$31
	.mask   0x40000000,-4
	.fmask  0x00000000,0
	.set    noreorder
	.set    nomacro
	addiu   $sp,$sp,-32
	sw      $fp,28($sp)
	move    $fp,$sp
	sw      $4,28($fp)
	sw      $5,32($fp)
	sw      $6,36($fp)
	li      $2,5
	sw      $2,8($fp)
	li      $2,2
	sw      $2,12($fp)
	li      $2,3
	sw      $2,16($fp)
	move    $sp,$fp
	lw      $fp,20($sp)
	addiu   $sp,$sp,24
	j       $31
	nop

	.set    macro
	.set    reorder
	.end    func
	.size   func, .-func

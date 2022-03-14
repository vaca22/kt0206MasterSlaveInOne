.section .text

.global QSPI_XIP_QuadSel_En

.func QSPI_XIP_QuadSel_En
QSPI_XIP_QuadSel_En:
	pushm $r0, $r4

	li $r0, #0xC0008010
	li $r1, #0x0
	li $r2, #0x1
	li $r3, #0x2
	li $r4, #0xC1

	.align 4 //2^4 = 16
	swi333 $r1, [$r0 + #0	]	//XIP_CTRL0 = 0x0
	swi333 $r4, [$r0 + #0x10]	//FIFO_CTRL = 0xC1
	swi333 $r3, [$r0 + #0x4	]	//XIP_CTRL1 = 0x2
	swi333 $r4, [$r0 + #0x10]	//FIFO_CTRL = 0xC1
	swi333 $r2, [$r0 + #0x0	]	//XIP_CTRL0 = 0x1
	.align 4

	popm $r0, $r4
	ret5 $lp
.endfunc


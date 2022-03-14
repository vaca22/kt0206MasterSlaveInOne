.section .text

.global QSPI_Continue_Enable

.func QSPI_Continue_Enable
QSPI_Continue_Enable:
	pushm $r0, $r4
	li $r4, #0xC0008010
	li $r0, #0x0
	li $r1, #0x6
	li $r2, #0x19
	li $r3, #0x1

	isb
	.align 4	//align=2^4=16
	swi333 $r0, [$r4+#0x0]	//XIP_CTRL0 = 0 	ExitXIP
	swi333 $r2, [$r4+#0x10]	//FIFO_CTRL = 0x19	FIFO_Flush
	swi333 $r1, [$r4+#0x4]	//XIP_CTRL1 = 0x06	ContinueEn
	swi333 $r2, [$r4+#0x10]	//FIFO_CTRL = 0x19	FIFO_Flush
	swi333 $r3, [$r4+#0x0]	//XIP_CTRL0 = 1 	EnterXIP
	isb
	.align 4
	popm $r0, $r4
	ret
.endfunc

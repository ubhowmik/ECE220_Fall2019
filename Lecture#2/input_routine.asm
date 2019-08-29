.ORIG x3000

	LD R2, New_Line
L1 	LDI R3, DSR
	BRzp L1
	STI R2, DDR

	LEA R2, Prompt

CHRLOOP	LDR R0, R2, #0
	
	BRz INPUT
DPOLL	
	LDI R1, DSR
	
	BRzp DPOLL
	
	STI R0, DDR
	
	ADD R2, R2, #1
	
	BRnzp CHRLOOP	


INPUT 	LDI R0, KBSR
     	BRzp INPUT
     	LDI R0, KBDR
L2		LDI R1, DSR
		BRzp L2
		STI R0, DDR
HALT

KBSR .FILL xFE00
KBDR .FILL xFE02

DSR	.FILL xFE04
DDR	.FILL xFE06

New_Line .FILL x000A ; Ascii Value for a newline
Prompt  .STRINGZ  "Input a Character>"


.END
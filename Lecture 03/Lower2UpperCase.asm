		.ORIG x3000	
;Convert Lowercase Letter to Uppercase
;Program terminate When press 1

		LD R2, TERM
		LD R3, ASCII_DIFF
		NOT R3, R3;
		ADD R3, R3, #1 ;2's complement of x0020
AGAIN	TRAP x23
		ADD R1,R2,R0 ; Test for Terminating Character
		BRz EXIT
		ADD R0,R0,R3
		TRAP x21 ;Out
		BR AGAIN

EXIT	TRAP x25 ;HALT

TERM 		.FILL 	xFFCF  ;1 is used as sentinel to terminate
ASCII_DIFF 	.FILL	x0020  ;Difference between the lowercase and Uppercase ASCII 
.END
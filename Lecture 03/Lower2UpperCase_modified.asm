		.ORIG x3000	
;Convert Lowercase Letter to Uppercase
;Program terminate When press 1

		LD R2, TERM
		LD R3, ASCII_DIFF
		NOT R3, R3;
		ADD R3, R3, #1 ;2's complement of x0020
		LD R4, LOWER_LIM
		LD R5, UPPER_LIM
AGAIN	TRAP x23
		ADD R1,R2,R0 ; Test for Terminating Character
		BRz EXIT
		ADD R1,R4,R0
		BRn INVALID
		ADD R1,R5,R0
		BRp INVALID
		ADD R0,R0,R3
		TRAP x21 ;Out
		BR AGAIN
		
INVALID LD R0,New_Line
		TRAP x21
		LEA R0, MSG
		PUTS   ;TRAP x22
		BR AGAIN		

EXIT	TRAP x25 ;HALT

TERM 		.FILL 	xFFCF  ;1 is used as sentinel to terminate
ASCII_DIFF 	.FILL	x0020  ;Difference between the lowercase and Uppercase ASCII 
LOWER_LIM 	.FILL   xFF9F  ; 2's complement of x0061 - ascii of a
UPPER_LIM	.FILL 	xFF86  ; 2's complement of x007A -ascii of z
MSG			.STRINGZ "Invalid Input. Enter Character Again:"
New_Line .FILL x000A ; Ascii Value for a newline
.END
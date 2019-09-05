; Push two values into the Stack
; Pop those values from the stack
; Add the Values and 
; put the result back into the stack

		.ORIG x3000
	LD R6, START	;load R6 with top of the stack
	AND R1, R1, #0	;initialize R1
	ADD R0, R1, #5	;put the value in R0 to be pushed
	JSR PUSH		;call PUSH subroutine
	ADD R5, R5, #0	;check for overflow	
	BRp OverFlow	;if overflows display error message
					; and exit
	AND R2, R2, #0	;push the 2nd value
	ADD R0, R2, #3
	JSR PUSH
	ADD R5, R5, #0
	BRp OverFlow

	AND R3, R3, #0	;pop the first value
	JSR POP			;call pop subroutine
	ADD R5, R5, #0	;check for underflow
	BRp UnderFlow	;if underflows exit with error message
	
	ADD R3,R0,#0	;pop the 2nd value
	AND R4, R4, #0
	JSR POP
	ADD R5, R5, #0
	BRp UnderFlow
	
	ADD R4,R0,#0
	ADD R0, R3, R4	;perform addition on two poped values
	JSR PUSH		;push the result onto stack
	JSR POP			;pop the result
	ADD R5, R5, #0	;error checking for underflow
	BRp UnderFlow

	LD R1, Ascii_Base ;display the result
	ADD R0,R0,R1
	OUT

	BR EXIT

OverFlow LEA R0, OverFlow_MSG
		 PUTS 
		 BR EXIT

OverFlow_MSG  .STRINGZ "There is an Overflow"

UnderFlow 	LEA R0, UnderFlow_MSG
			PUTS 
			BR EXIT

EXIT 	HALT

UnderFlow_MSG  .STRINGZ "There is an Underflow"
Ascii_Base 	   .FILL x30

POP		AND R5, R5, #0 	; R5<--Success
		ST R1, Save_R1	; Save register that
		ST R2, Save_R2	;are needed by the POP
		LD R1, Base		;Base contain -x4000
		ADD R2,R6,R1	;compare stack pointer to x4000
		BRz Fail_exit	;branch if the stack is empty
		LDR R0, R6, #0	;the actual POP
		ADD R6,R6, #1	;adjust stack pointer
		BR Success_Exit

PUSH	AND R5, R5,#0	; R5<--Success
		ST R1, Save_R1	;save registers that are needed 
		ST R2, Save_R2	;by the PUSH
		LD R1, MAX		;MAX contains -x3FFB
		ADD R2,R6,R1	;compare stack pointer to x3FFB
		BRz Fail_exit	;branch if the stack is full
		ADD R6,R6, #-1	;adjust stack pointer
		STR R0, R6, #0	;actual PUSH
		BR Success_Exit
	
Success_Exit LD R2, Save_R2	;restore original register values
			 LD R1, Save_R1	
			 RET 			;return to the caller function
		
Fail_exit ADD R5,R5,#1		;R5<--failure
		  LD R2, Save_R2	;restore original register values
		  LD R1, Save_R1
		  RET
		  
START .FILL x4000
BASE .FILL xC000 ; 2's complement of x4000
MAX  .FILL xC005 ; 2's complement of x3FFB
Save_R1 .BLKW  #1
Save_R2 .BLKW  #1
.END
; stack implementation

.ORIG x3000

	;; R1: address of the char to be read
	;; R2: char being read
	;; R3, R4: operands popped from stack
	;; R0: item to push on stack
	;; R5: ASCII values on '0', '9', '+', etc. used for checks
	LEA R1, string_start
READ_LOOP	
	;; read char
	LDR R2, R1, #0
	BRz DONE_READ 		;; if end finish
	;; prepare output 
	ADD R0, R2, #0
	OUT
	;; check for number '0' <= R2 <= '9'
	LD R5, char_val_0
	NOT R5, R5
	ADD R5, R5,#1
	ADD R3, R2, R5	; R3 < '0' i.e., R3 <- R2 - '0'
	BRN HANDLE_OPERATORS
	NOT R3, R2
	ADD R3, R3, #1		; R3 <- -R2
	LD R5, char_val_9
	ADD R5, R5, R3		; R5 <-  '9' - R2
	BRN DONE_CHAR
	;; handle operands
	;; convert and push operands
	LD R5, char_val_0
	NOT R5, R5
	ADD R5, R5, #1
	ADD R0, R5, R0		; R0 <- numerical value of operand
	JSR PUSH		; PUSH R0
	BRNZP DONE_CHAR	

HANDLE_OPERATORS
	;; non_chars
	JSR POP
	ADD R3, R0, #0		; R3 <- POP
	JSR POP
	ADD R4, R0, #0		; R4 <- POP
	;; do operators
	NOT R2, R2
	ADD R2, R2, #1		; R2 <- negation of char operator
	LD R5, char_val_plus
	ADD R5, R2, R5		; R5 <- '+' - R2
	BRNP NOT_ADD
	ADD R0, R3, R4		;R0 <- R3 + R4
	JSR PUSH		;PUSH result
	BRNZP DONE_CHAR

	;; not add
NOT_ADD
	;; subtraction
	LD R5, char_val_sub
	ADD R5, R2, R5		; R5 <- '-' - R2
	BRNP NOT_MINUS
	NOT R4, R4
	ADD R4, R4, #1
	ADD R0, R3, R4		; R0 <- R3 - R4
	JSR PUSH
	BRNZP DONE_CHAR

	;; not subtraction
NOT_MINUS
	;; multiplication
	LD R5, char_val_mul
	ADD R5, R2, R5		; R5 <- '*' - R2
	BRNP NOT_MULTI
	AND R0, R0, #0
MULT_LOOP
	ADD R0, R4, R0
	ADD R3, R3, #-1
	BRP MULT_LOOP
	JSR PUSH
	BRNZP DONE_CHAR
	;; not multiplication
NOT_MULTI
	BRNZP DONE_CHAR
		
DONE_CHAR	
	ADD R1, R1, #1
	BRNZP READ_LOOP
	
DONE_READ	
	HALT

	
	
	;; POP
	;;  IN: nothing
	;;  OUT: if stack is successful (not empty) then R0 will contain the value poped R5 will be 1
	;; 	else R5 will be 0
POP
	;;  save registers
	ST R3, POP_save_R3
	ST R4, POP_save_R4
	;; check empty
	LD R4, STACK_TOP
	LD R3, STACK_START
	;;  clear register 5
	AND R5, R5, #0
	;; stack underflow stack_top = stack_start
	NOT R3, R3
	ADD R3, R3, #1
	ADD R3, R3, R4
	BRZ STACK_UNDERFLOW
	ADD R4, R4, #1
	LDR R0, R4, #0
	;; update top
	ST R4, STACK_TOP
	BRnzp POP_DONE
STACK_UNDERFLOW
	ADD R5, R5, #1
POP_DONE
	;;  restore register
	LD R3, POP_save_R3
	LD R4, POP_save_R4
	RET

;;  push data
POP_save_R3 .BLKW #1
POP_save_R4 .BLKW #1

	
	;; PUSH
	;; IN: R0 will contain value to be pushed
	;; OUTPUT: R5 = 0 success if stack is not full, update stack
	;;  	      = 1 fail if stack is full, stack remains unchanged
PUSH
	;;  save registers
	ST R3, PUSH_save_R3
	ST R4, PUSH_save_R4
	;; check full
	LD R4, STACK_TOP
	LD R3, STACK_END
	;;  
	AND R5, R5, #0		
	;; check stack_end - 1 = stack_top
	ADD R3, R3, #-1
	NOT R3, R3
	ADD R3, R3, #1		; R3 <- -(stack_end - 1)
	ADD R3, R3, R4
	BRz STACK_OVERFLOW
	;; save item
	STR R0, R4, #0		;
	ADD R4, R4, #-1
	ST R4, STACK_TOP
	BRnzp PUSH_DONE
STACK_OVERFLOW
	ADD R5, R5, #1
PUSH_DONE
	;;  restore register
	LD R3, PUSH_save_R3
	LD R4, PUSH_save_R4
	RET

;;  push data
PUSH_save_R3 .BLKW #1
PUSH_save_R4 .BLKW #1

	
; data
STACK_TOP .FILL x4000 	
STACK_START .FILL x4000
STACK_END .FILL x3F00
string_start .STRINGZ "4a3+4*"
char_val_0 .Fill x30
char_val_9 .Fill x39
char_val_plus .Fill x2B
char_val_sub .Fill x2D
char_val_mul .Fill x2A
	
	.END

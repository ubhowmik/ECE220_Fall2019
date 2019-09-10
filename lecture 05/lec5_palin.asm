.ORIG x3000

;;; checking a palindrome

MAIN
	;; R1: addres of char to read
	;;;  R2: char being read
	;; R5 = 1 not palindrome
	;; = 0 palindrome
	AND R5, R5, #0
	LEA R1, string_start
READ_LOOP
	LDR R2, R1, #0
	BRZ DONE_READ
	ADD R0, R2, #0
	ST R5, saveR5palin
	JSR PUSH
	LD R5, saveR5palin
	ADD R1, R1, #1
	BRNZP READ_LOOP
DONE_READ
	LEA R1, string_start
CHECK_LOOP
	LDR R2, R1, #0
	BRZ DONE
	ST R5, saveR5palin
	JSR POP			;R0 <- char
	LD R5, saveR5palin
	NOT R2, R2
	ADD R2, R2, #1
	ADD R2, R2, R0		;R2 <- char - popped val
	BRNP MISMATCH
	ADD R1, R1, #1
	BRNZP CHECK_LOOP
MISMATCH ADD R5, R5, #1
DONE	
	HALT

ASCII .fill  x30 
STRING_start .stringz "kayak"	
	
	

saveR5palin .BLKW 1



;;; Pushes R0 at the top of the stack
;;; IN: R0
;;; OUT: R5 (0-success; 1 fail)
;;; USES: R3: stack end, R4: stack_top




	
PUSH
	;; Save registers
	ST R3, saveR3push
	ST R4, saveR4push
	;; Set R5 to 0
	AND R5, R5, #0
	;; Lod top and end
	LD R3, stack_end
	LD R4, stack_top
	;; check full: end-1 = top
	ADD R3, R3, #-1
	NOT R3, R3
	ADD R3, R3, #1
	Add R3, R4, R3		;R3 = top - (end -1)
	BRz OVERFLOW
	;; not overflow
	STR R0, R4, #0		;push R0
	ADD R4, R4, #-1
	ST R4, stack_top	;move top of stack up by one
	BRNZP PUSH_DONE
OVERFLOW
	ADD R5, R5, #1
PUSH_DONE
	;; restore registers
	LD R3, saveR3push
	LD R4, saveR4push
	RET
	
	saveR4push .BLKW 1
	saveR3push .BLKW 1
	
;;; POPs and stores in R0
;;; IN: none
;;; OUT: R5 (0-success; 1 fail); poped value in R0
;;; USES: R3: stack_start, R4: stack_top
	
POP
	;; Save registers
	ST R3, saveR3pop
	ST R4, saveR4pop
	;; Set R5 to 0
	AND R5, R5, #0
	;; Lod top and end
	LD R3, stack_start
	LD R4, stack_top
	;; check full: start = top
	NOT R3, R3
	ADD R3, R3, #1
	Add R3, R4, R3		;R3 = top - start
	BRz UNDERFLOW
	;; not underflow
	ADD R4, R4, #1		;update stack pointer	
	LDR R0, R4, #0		;R0<- popped value
	ST R4, stack_top
	BRNZP POP_DONE
UNDERFLOW
	ADD R5, R5, #1
POP_DONE
	;; restore registers
	LD R3, saveR3pop
	LD R4, saveR4pop
	RET
	
	saveR4pop .BLKW 1
	saveR3pop .BLKW 1

	stack_start .FILL x3600
	stack_end .FILL x35F0
	stack_top .FILL x3600
	.END

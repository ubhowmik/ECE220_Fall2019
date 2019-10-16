.ORIG x3000
; push argument
    LD R6, STACK_TOP
    AND R0,R0,#0
    ADD R0,R0,#3
    STR R0,R6,#0
; call subroutine
    JSR FACTORIAL
; pop return value from run-time stack (to R0) 
    LDR R0,R6,#0
    ADD R6, R6, #+1
    HALT

FACTORIAL:
; push callee’s bookkeeping info onto the run-time stack
; allocate space in the run-time stack for return value
    ADD R6, R6, #-1
; store caller’s return address and frame pointer 
    ADD R6, R6, #-1
    STR R7, R6, #0
    ADD R6, R6, #-1
    STR R5, R6, #0
; allocate memory for local variable fn
    ADD R6, R6, #-1
    ADD R5, R6, 0
; if (n>0)
    LDR R1, R5, #4
    ADD R2, R1, #-1
    BRn ELSE
; compute fn = n * factorial(n-1)
; caller-built stack for factorial(n-1) function call ; push n-1 onto run-time stack
    ADD R6, R6, #-1
    STR R2, R6, #0
; call factorial subroutine
    JSR FACTORIAL
; pop return value from run-time stack (to R0) 
    LDR R0, R6, #0
    ADD R6, R6, #1
; pop function argument from the run-time stack 
    ADD R6, R6, #1
; multiply n by the return value (already in R0)  
    LDR R1, R5, #4
    ;MUL R0, R0, R1 ; R0 <- n * factorial(n-1) 
    ST R7, SAVE_R7
    JSR MULT
    LD R7, SAVE_R7
    ADD R0, R2, #0
; store result in memory for fn
    STR R0, R5, #0
; done with this branch
    BRnzp RETURN
ELSE:
; store value of 1 in memory for fn 
    AND R2, R2, #0
    ADD R2, R2, #1
    STR R2, R5, #0
; tear down the run-time stack and return
RETURN:
; write return value to the return entry
    LDR R0, R5, #0
    STR R0, R5, #3
; pop local variable(s) from the run-time stack
    ADD R6, R6, #1
; restore caller’s frame pointer and return address 
    LDR R5, R6, #0
    ADD R6, R6, #1
    LDR R7, R6, #0
    ADD R6, R6, #1
; return control to the caller function
    RET
; multiply subroutine
; input should be in R0 and R1
; output should be in R2
MULT
    ; save R3
    ST R3, SAVE_R3
    ; reset R2 and initialize R3
    AND R2, R2, #0
    ADD R3, R0, #0
    ; perform multiplication
    MULT_LOOP
    ADD R3, R3, #-1
    BRn MULT_DONE
    ADD R2, R2, R1
    BRnzp MULT_LOOP
    MULT_DONE
    ; restore R0
    LD R3, SAVE_R3
    RET 

SAVE_R3             .BLKW #1
SAVE_R7             .BLKW #1
STACK_TOP           .FILL x4000
.END
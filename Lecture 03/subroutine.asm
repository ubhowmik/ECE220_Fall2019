; compute y=3x^3-6x^2+7x for x > 0
; assume that value X is located in memory at x4000
; put resulting value Y to memory at x4001
;
       .ORIG x3000
       LDI R3, Xaddr             ; load X
;
; compute x^2 and store it in R4
;
       ADD R1, R3, #0          ; R1 = X
       ADD R2, R3, #0          ; R2 = X
       JSR MULT                ; R0 = X x X
       ADD R4, R0, #0          ; R4 = X^2
;
; compute x^3 and store it in R5
;
       ADD R1, R4, #0          ; R1 = X x X
       JSR MULT                ; R0 = X x X x X
       ADD R5, R0, #0          ; R5 = X^3
;
; compute 3 x X^3 and store it in R5
;
       AND R1, R1, #0          ; clear R1
       ADD R1, R1, #3          ; R1 = 3
       ADD R2, R5, #0          ; R2 = X^3
       JSR MULT                ; R0 = 3 x X^3
       ADD R5, R0, #0          ; R5 = 3 x X^3
;
; compute 6 x X^2 and store it in R4
;
       AND R1, R1, #0          ; clear R1
       ADD R1, R1, #6          ; R1 = 6
       ADD R2, R4, #0          ; R2 = X^2
       JSR MULT                ; R0 = 6 x X^2
       ADD R4, R0, #0          ; R4 = 6 x X^2
;
; compute 7 x X and store it in R3
;
       AND R1, R1, #0          ; clear R1
       ADD R1, R1, #7          ; R1 = 7
       ADD R2, R3, #0          ; R2 = X
       JSR MULT                ; R0 = 7 x X
       ADD R3, R0, #0          ; R3 = 7 x X
;
; subtract 6 x X^2 (R4) from 3 x X^3 (R5) and store results in R6
;
       ADD R1, R5, #0          ; R1 = 3 x X^3
       ADD R2, R4, #0          ; R2 = 6 x X^2
       JSR SUBTR               ; R0 = 3 x X^3 - 6 x X^2
       ADD R6, R0, #0          ; R6 = 3 x X^3 - 6 x X^2
;
; add 7 x X (R3) to 3 x X^3 - 6 x X^2 (R6) and store result in R6
;
       ADD R6, R6, R3          ; R6 = 3 x X^3 - 6 x X^2 + 7 x X
;
; store results in memory
;
       STI R6, Yaddr
;
       HALT
;
Xaddr  .FILL x4000     ; argument location
Yaddr  .FILL x4001     ; result location
; insert source code for SUBTR and MULT subroutines here

; MULT subroutine multiplies two 2s' complement numbers
; IN: R1, R2
; OUT R0 = R1 x R2
MULT    ST R1, MULTSaveR1      ; store R1
        AND R0, R0, #0         ; R0 = 0
LOOPADD ADD R0, R0, R2         ; R0 = R0 + R2
        ADD R1, R1, #-1        ; decrease counter
        BRp LOOPADD
        LD R1, MULTSaveR1      ; restore R1
        RET
MULTSaveR1   .BLKW 1

; SUBTR subroutine computes difference of two 2s’ complement numbers
; IN: R1, R2
; OUT: R0←R1-R2
SUBTR   ST R2, SaveR2 ; save R2 in memory
        NOT R2, R2
        ADD R2, R2, #1 ; do not use R7 since it is needed to return
        ADD R0, R1, R2
        LD R2, SaveR2 ; restore R2 from memory
        RET
SaveR2  .BLKW 1 ; memory for saving R2

       .END

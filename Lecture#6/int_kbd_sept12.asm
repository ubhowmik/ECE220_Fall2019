.ORIG   x3000
    LEA R0,ISR_KB
    STI R0,KBINTV ;load ISR address to INTV (M[x0180] <- ISR_KB)
    LD  R3,EN_IE
    STI R3,KBSR ;enable IE bit of KBSR

AGAIN
    LD  R0,NUM2 ;infinite loop printing '2'
    OUT     ;Interrrupt during this OUT can cause re-entrant problem(lc3web)
            ;due to R7-save in OUT (which is not necessary, update needed).
    BRnzp   AGAIN

ISR_KB
    ST  R0,SaveR0 ;callee-save
    ST  R7,SaveR7 ;callee-save
    LDI R0,KBDR ;read a charcter from keyboard and clear ready bit
    HALT
    LD  R0,SaveR0
    LD  R7,SaveR7
    RTI
EN_IE   .FILL   x4000 ;enable IE 0100_0000_0000_0000
NUM2    .FILL   x0032 ;'2'
KBSR    .FILL   xFE00
KBDR    .FILL   xFE02
KBINTV  .FILL   x0180 ;INT vector table address for keyboard
SaveR0  .BLKW   #1
SaveR7  .BLKW   #1
.END

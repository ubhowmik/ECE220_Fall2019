; Use the Following loink to Execute the following code 
; https://courses.grainger.illinois.edu/ece220/fa2019/lc3web/index.html

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
DPOLL	LDI R1, DSR  ; Test Display Regster is ready
		BRzp DPOLL
		STI R0, DDR
    LD  R0,SaveR0
    LD  R7,SaveR7
		HALT
		RTI
EN_IE   .FILL   x4000 ;enable IE 0100_0000_0000_0000
NUM2    .FILL   x0032 ;'2'
KBSR 	.FILL 	xFE00     ; Address of KBSR
KBDR 	.FILL 	xFE02	 ; Address of KBDR
DSR  	.FILL 	xFE04 	 ; Address of DSR
DDR  	.FILL 	xFE06     ; Address of DDR
KBINTV  .FILL   x0180 ;INT vector table address for keyboard
SaveR0  .BLKW   #1
SaveR7  .BLKW   #1
.END

.ORIG x3000

;;R5 - frame pointer
;;R6 - stack pointer
;;MAIN
LD R6, STACK
LD R5, STACK
LD R1, ND_VAL
STR R1, R5, #0    ; push nd (x6000) to stack
JSR INORDER
HALT

;;INORDER TRAVERSAL
INORDER
;;Part 1 - push book keeping info
;allocate space for return value
ADD R6, R6, #-1
;Push return address to stack
ADD R6, R6, #-1
STR R7, R6, #0
;Store old frame pointer
ADD R6, R6, #-1
STR R5, R6, #0
;Set up new frame pointer
ADD R5, R6, #-1

;;Part 2 - implement function logic
;if (nd == NULL) skip to the end (Done)
LDR R1, R5, #4
BRz DONE
;else 
;inorder(nd->left);
LDR R2, R1, #1        ;load nd->left to R2
ADD R6, R6, #-1
STR R2, R6, #0        ;push nd->left to stack
JSR INORDER          ;;;;;;;;;;;;;;;;;;;;;;;;;
ADD R6, R6, #2  ;(left return);stack tear down
;printf("%c", nd->data);
LDR R1, R5, #4
LDR R0, R1, #0
OUT
;inorder(nd->right); 
;LDR R1, R5, #4        ;reload nd first
LDR R3, R1, #2        ;load nd->right to R3
ADD R6, R6, #-1       
STR R3, R6, #0        ;push nd->right to stack
JSR INORDER           ;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ADD R6, R6, #2 ;(right return);stack tear down

;;Part 3 - tear down part of activation record (prepare to return)
DONE
LDR R5, R6, #0        ;restore old frame pointer
ADD R6, R6, #1

LDR R7, R6, #0        ;restore return address
ADD R6, R6, #1

RET


STACK .FILL x7000
ND_VAL .FILL x6000

.END
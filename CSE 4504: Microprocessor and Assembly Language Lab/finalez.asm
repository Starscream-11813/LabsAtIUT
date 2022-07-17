
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

;org 100h
;
;.STACK 100h
;
;.DATA
;linefeed db 13, 10, "$"
;row dw 1
;.CODE
;main proc
;    
;    mov CX, 5
;    
;    outer_loop:
;    push CX
;    mov CX, row
;    
;    inner_loop:
;    mov AH, 2
;    mov DL, '*'
;    int 21h
;    loop inner_loop
;    inc row
;    pop CX
;    ;newline
;    mov BL, AL
;    mov AH, 09
;    mov DX, offset linefeed
;    int 21h
;    loop outer_loop
;    
;    
;    
;main endp
;
;ret


;org 100h
;
;.STACK 100h
;
;.DATA
;linefeed db 13, 10, "$"
;arr DB 5 DUP(?)
;inputprompt DB 'Input: $'
;ascsortmessage DB 'Ascending: $'
;ascsortarr DB 5 DUP(0)
;descsortmessage DB 'Descending: $'
;
;.CODE
;main proc
;    mov AX, @DATA
;    mov DS, AX
;    mov AX, AX
;    
;    ;Display the Input prompt
;    mov DX, offset inputprompt
;    lea DX, inputprompt
;    mov AH, 9
;    int 21h
;    
;    mov CX, 5           ; Take 5 elements as input
;    mov SI, 0   
;    mov AH, 1
;    
;    ; Take the inputs and store them in arr[]
;    inputloop: 
;        int 21H     
;        and AL, 0FH         ; Convert from ASCII value to actual value
;        mov arr[SI], AL
;        inc SI
;    loop inputloop
;    
;    ;newline
;    mov BL, AL
;    mov AH, 09
;    mov DX, offset linefeed
;    int 21h
;    
;    ;print message
;    mov DX, offset ascsortmessage    ; Load Effective Address of the outputprompt in DX register
;    lea DX, ascsortmessage
;    mov AH, 9
;    int 21h
;    
;    mov DI, 0
;    mov DX, 5
;    
;    outerloop:
;        
;        mov CX, 5
;        lea DI, arr
;        innerloop:
;            
;            mov AL, [DI]
;            cmp AL, [DI+1]
;            jl sorted
;            
;            xchg AL, [DI+1]
;            mov [DI], AL
;            
;            sorted:
;                inc DI
;        
;        loop innerloop
;        
;        dec DX
;    
;    jnz outerloop
;    
;    mov SI, 0
;    mov CX, 5
;    mov AH, 2
;    
;    outputloop1:                   ; Iterate through arr[] and print the elements
;    mov DL, arr[SI]
;    add DL, 30h
;    int 21h
;    inc SI                         ; Print whitespace
;    call printSpace
;    loop outputloop1
;    
;    ;newline
;    mov BL, AL
;    mov AH, 09
;    mov DX, offset linefeed
;    int 21h
;        
;    ;print message
;    mov DX, offset descsortmessage    ; Load Effective Address of the outputprompt in DX register
;    lea DX, descsortmessage
;    mov AH, 9
;    int 21h
;    
;    mov SI, 4
;    mov CX, 5
;    mov AH, 2
;    
;    outputloop2:                   ; Iterate through arr[] and print the elements
;    mov DL, arr[SI]
;    add DL, 30h
;    int 21h
;    dec SI                         ; Print whitespace
;    call printSpace
;    loop outputloop2
;    
;main endp
;
;ret
;
;printSpace proc                    ; For printing spaces
;    mov DL, ' '
;    mov AH, 2
;    int 21h
;    ret
;printSpace endp

;org 100h
;
;.STACK 100h
;
;.DATA
;  NUM1 DW ?
;  NUM2 DW ?
;  GCD DW ?
;  inputprompt DB 'Input: $'
;  gcdmessage DB 'GCD: $'
;  linefeed db 13, 10, "$"
;
;.CODE
;main proc
;    mov AX, @DATA
;    mov DS, AX
;    mov AX, AX
;    
;    ;Display the Input prompt
;    mov DX, offset inputprompt
;    lea DX, inputprompt
;    mov AH, 9
;    int 21h
;    
;    ;input
;    mov AH, 1
;	int 21h
;	mov NUM1, AX
;	
;	call printSpace
;	
;	;input
;    mov AH, 1
;	int 21h
;    mov NUM2, AX
;    
;    mov AX,NUM1   ;Move the first number to AX.
;    mov BX,NUM2   ;Move the second number to BX.
;    
;    top:
;    cmp AX, BX
;    je exit
;    jb exchange
;    
;    top1:
;    mov DX, 0
;    div BX
;    cmp DX, 0
;    je exit
;    mov AX, DX
;    jmp top
;    
;    exchange:
;    xchg AX, BX
;    jmp top1
;    
;    exit:
;    mov GCD, BX
;    
;    ;newline
;    mov BL, AL
;    mov AH, 09
;    mov DX, offset linefeed
;    int 21h
;    
;    ;print message
;    mov DX, offset gcdmessage    ; Load Effective Address of the outputprompt in DX register
;    lea DX, gcdmessage
;    mov AH, 9
;    int 21h
;    
;    ;print output stored in BL
;    mov AH, 2
;    mov DX, GCD
;    add DX, 30h
;    int 21h
;    
;main endp
;
;ret
;
;printSpace proc                    ; For printing spaces
;    mov DL, ' '
;    mov AH, 2
;    int 21h
;    ret
;printSpace endp

;org 100h
;
;.STACK 100h
;
;.DATA
;arr DB 5 DUP(?)
;inputprompt DB 'Input: $'
;outputprompt DB 'Output: $'
;summessage DB 'Sum: $'
;linefeed db 13, 10, "$"
;sum db 0
;numleft db 0
;numright db 0009h
;alphaleft db 000Ah
;alpharight db 000Fh
;
;.CODE
;main proc
;    
;    mov AX, @DATA
;    mov DS, AX
;    mov AX, AX
;    
;    ;Display the Input prompt
;    mov DX, offset inputprompt
;    lea DX, inputprompt
;    mov AH, 9
;    int 21h
;    
;    mov CX, 5           ; Take 5 elements as input
;    mov SI, 0   
;    mov AH, 1
;    
;    ; Take the inputs and store them in arr[]
;    inputloop: 
;    int 21H     
;    and AL, 0FH         ; Convert from ASCII value to actual value
;    add sum, AL
;    mov arr[SI], AL
;    inc SI
;    loop inputloop
;    
;    ;newline
;    mov BL, AL
;    mov AH, 09
;    mov DX, offset linefeed
;    int 21h
;    
;    ;print message
;    mov DX, offset outputprompt    ; Load Effective Address of the outputprompt in DX register
;    lea DX, outputprompt
;    mov AH, 9
;    int 21h
;    
;    call printSpace
;    
;    ;print message
;    mov DX, offset summessage    ; Load Effective Address of the primemessage in DX register
;    lea DX, summessage
;    mov AH, 9
;    int 21h
;    
;    call printSpace
;    
;    mov CL, numright
;    cmp sum, CL
;    jle numeric
;    add sum, 0037h
;    jmp bot
;    
;    numeric:
;    add sum, 0030h
;    
;    bot:
;    ;inc sum
;    ;print output stored in sum
;    mov AH, 2
;    mov DL, sum
;    int 21h
;    
;    
;    main endp
;
;ret
;
;printSpace proc                    ; For printing spaces
;    mov DL, ' '
;    mov AH, 2
;    int 21h
;    ret
;printSpace endp 

;org 100h
;   
;   ;mov ax, -5
;   ;sub ax, ax
;   mov ax, 5
;   cmp ax, 5
;   jc label1
;   label1:
;   
;ret

; Author: Syed Rifat Raiyan
; Student ID: 180041205
; Sorting Algorithm: Bubble Sort

;org 100h
;
;.STACK 100h
;
;.DATA
;linefeed db 13, 10, "$"
;arr DB 5 DUP(?)
;inputPrompt DB 'Input: $'
;ascSortMessage DB 'Ascending: $'
;
;.CODE
;main proc
;    mov AX, @DATA       ; Initializing the DS register with the Data Segment number
;    mov DS, AX
;    mov AX, AX
;    
;    ; Display the "Input: " prompt
;    mov DX, OFFSET inputPrompt
;    lea DX, inputPrompt
;    mov AH, 9
;    int 21h
;    
;    mov CX, 5           ; Take 5 elements as input
;    mov SI, 0   
;    mov AH, 1           ; Set function number to Single Character Input
;    
;    ; Take the inputs and store them in arr[]
;    inputLoop: 
;        int 21H     
;        and AL, 0FH         ; Convert from ASCII value to actual value
;        mov arr[SI], AL
;        inc SI
;        call printSpace     ; Print whitespace as shown in Sample I/O
;        mov AH, 1           ; Set function number to Single Character Input again
;    loop inputLoop
;    
;    ; Newline
;    mov BL, AL
;    mov AH, 09
;    mov DX, OFFSET linefeed
;    int 21h
;    
;    ; Print "Ascending: " Message
;    mov DX, OFFSET ascSortMessage   ; Load Effective Address of the ascSortMessage in DX register
;    lea DX, ascSortMessage
;    mov AH, 9
;    int 21h
;    
;    mov DI, 0
;    mov DX, 5           ; Length of array arr[] will always be 5
;    
;    outerLoop:
;        
;        mov CX, 5
;        lea DI, arr
;        innerLoop:
;            
;            mov AL, [DI]
;            cmp AL, [DI+1]
;            jl isSorted
;            
;            xchg AL, [DI+1]         ; If [DI] is greater than or equal to [DI+1] then we need to swap
;            mov [DI], AL
;            
;            isSorted:               ; If [DI] is lesser than [DI+1] then proceed to the next element
;                inc DI
;        
;        loop innerLoop
;        
;        dec DX
;    
;    jnz outerLoop                   ; Loop until DX is 0
;    
;    mov SI, 0
;    mov CX, 5
;    mov AH, 2                       ; Set function number to Single Character Output
;    
;    outputLoop:                   ; Iterate through arr[] and print the sorted elements
;        mov DL, arr[SI]
;        add DL, 30h
;        int 21h
;        inc SI                         
;        call printSpace                ; Print whitespace
;    loop outputLoop
;    
;    ;newline
;    mov BL, AL                         ; Set function number to Character String Output
;    mov AH, 09
;    mov DX, OFFSET linefeed
;    int 21h
;    
;main endp
;
;ret
;
;printSpace proc                    ; Procedure for printing spaces
;    mov DL, ' '                    ; Set function number to Single Character Output
;    mov AH, 2
;    int 21h
;    ret
;printSpace endp  

; Author: Syed Rifat Raiyan
; Student ID: 180041205
; Sorting Algorithm: Bubble Sort

org 100h

.STACK 100h

.DATA
linefeed db 13, 10, "$"
arr DB 5 DUP(?)
inputPrompt DB 'Input: $'
ascSortMessage DB 'Ascending: $'

.CODE
main proc
    mov AX, @DATA       ; Initializing the DS register with the Data Segment number
    mov DS, AX
    mov AX, AX
    
    ; Display the "Input: " prompt
    mov DX, OFFSET inputPrompt
    lea DX, inputPrompt
    mov AH, 9
    int 21h
    
    mov CX, 5           ; Take 5 elements as input
    mov SI, 0   
    mov AH, 1           ; Set function number to Single Character Input
    
    ; Take the inputs and store them in arr[]
    inputLoop: 
        int 21H     
        and AL, 0FH         ; Convert from ASCII value to actual value
        mov arr[SI], AL
        inc SI
        call printSpace     ; Print whitespace as shown in Sample I/O
        mov AH, 1           ; Set function number to Single Character Input again
    loop inputLoop
    
    ; Newline
    mov BL, AL
    mov AH, 09
    mov DX, OFFSET linefeed
    int 21h
    
    ; Print "Ascending: " Message
    mov DX, OFFSET ascSortMessage   ; Load Effective Address of the ascSortMessage in DX register
    lea DX, ascSortMessage
    mov AH, 9
    int 21h
    
    mov DI, 0
    mov DX, 5           ; Length of array arr[] will always be 5
    
    outerLoop:
        
        mov CX, 5
        lea DI, arr
        innerLoop:
            
            mov AL, [DI]
            cmp AL, [DI+1]
            jl isSorted
            
            xchg AL, [DI+1]         ; If [DI] is greater than or equal to [DI+1] then we need to swap
            mov [DI], AL
            
            isSorted:               ; If [DI] is lesser than [DI+1] then proceed to the next element
                inc DI
        
        loop innerLoop
        
        dec DX
    
    jnz outerLoop                   ; Loop until DX is 0
    
    mov SI, 0
    mov CX, 5
    mov AH, 2                       ; Set function number to Single Character Output
    
    outputLoop:                   ; Iterate through arr[] and print the sorted elements
        mov DL, arr[SI]
        add DL, 30h
        int 21h
        inc SI                         
        call printSpace                ; Print whitespace
    loop outputLoop
    
    ;newline
    mov BL, AL                         ; Set function number to Character String Output
    mov AH, 09
    mov DX, OFFSET linefeed
    int 21h
    
main endp

ret

printSpace proc                    ; Procedure for printing spaces
    mov DL, ' '                    ; Set function number to Single Character Output
    mov AH, 2
    int 21h
    ret
printSpace endp

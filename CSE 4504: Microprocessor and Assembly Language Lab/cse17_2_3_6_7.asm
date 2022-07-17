
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

.STACK 100h

.DATA
arr DB 5 DUP(?)
inputprompt DB 'Input: $'
largestmessage DB 'Largest: $'
smallestmessage DB 'Smallest: $'
summessage DB 'Sum: $'
averagemessage DB 'Average: $'
ascsortmessage DB 'Ascending: $'
ascsortarr DB 5 DUP(0)
descsortmessage DB 'Descending: $'
linefeed db 13, 10, "$"

.CODE
main proc

    mov AX, @DATA
    mov DS, AX
    mov AX, AX
    
    ;Display the Input prompt
    mov DX, offset inputprompt
    lea DX, inputprompt
    mov AH, 9
    int 21h
    
    mov CX, 5           ; Take 5 elements as input
    mov SI, 0   
    mov AH, 1
    
    ; Take the inputs and store them in arr[]
    inputloop: 
    int 21H     
    and AL, 0FH         ; Convert from ASCII value to actual value
    mov arr[SI], AL
    inc SI
    loop inputloop
    
    
    ;newline
    mov BL, AL
    mov AH, 09
    mov DX, offset linefeed
    int 21h
    
    ;print message
    mov DX, offset largestmessage    ; Load Effective Address of the outputprompt in DX register
    lea DX, largestmessage
    mov AH, 9
    int 21h
    
    mov DI, 0
    ;mov SI, offset arr
    ;mov DI, offset res
    mov CX, 5
    xor BL, BL
    
    iterationloop:
    
    cmp BL, arr[DI]
    jl maxfound
    
    jmp bottom
    
    maxfound:
    mov BL, arr[DI]
    
    bottom:
    
    inc DI
    loop iterationloop
    
    add BL, 0030h
    ;print output stored in BL
    mov AH, 2
    mov DL, BL
    int 21h
    
    ;newline
    mov BL, AL
    mov AH, 09
    mov DX, offset linefeed
    int 21h
    
    ;print message
    mov DX, offset smallestmessage    ; Load Effective Address of the outputprompt in DX register
    lea DX, smallestmessage
    mov AH, 9
    int 21h
    
    mov DI, 0
    ;mov SI, offset arr
    ;mov DI, offset res
    mov CX, 5
    xor BL, BL
    mov BL, 9
    
    
    iterationloop1:
    
    cmp BL, arr[DI]
    jg minfound
    
    jmp bottom1
    
    minfound:
    mov BL, arr[DI]
    
    bottom1:
    
    inc DI
    loop iterationloop1
    
    add BL, 0030h
    ;print output stored in BL
    mov AH, 2
    mov DL, BL
    int 21h
    
    ;newline
    mov BL, AL
    mov AH, 09
    mov DX, offset linefeed
    int 21h
    
    ;print message
    mov DX, offset summessage    ; Load Effective Address of the outputprompt in DX register
    lea DX, summessage
    mov AH, 9
    int 21h
    
    mov DI, 0
    ;mov SI, offset arr
    ;mov DI, offset res
    mov CX, 5
    xor BL, BL
    
    
    iterationloop2:
    
    add BL, arr[DI]
    
    inc DI
    loop iterationloop2
    
    add BL, 0030h
    ;print output stored in BL
    mov AH, 2
    mov DL, BL
    int 21h
    
    ;newline
    mov BL, AL
    mov AH, 09
    mov DX, offset linefeed
    int 21h
    
    ;print message
    mov DX, offset averagemessage    ; Load Effective Address of the outputprompt in DX register
    lea DX, averagemessage
    mov AH, 9
    int 21h
    
    mov DI, 0
    ;mov SI, offset arr
    ;mov DI, offset res
    mov CX, 5
    xor BL, BL
    
    
    iterationloop3:
    
    add BL, arr[DI]
    
    inc DI
    loop iterationloop3
    
    mov AX, BX
    mov BL, 5
    ;mov CX, 5
    div BL
    mov BL, AL
    add BL, 0030h
    ;print output stored in BL
    mov AH, 2
    mov DL, BL
    int 21h
    
    ;newline
    mov BL, AL
    mov AH, 09
    mov DX, offset linefeed
    int 21h
    
    ;print message
    mov DX, offset ascsortmessage    ; Load Effective Address of the outputprompt in DX register
    lea DX, ascsortmessage
    mov AH, 9
    int 21h
    
    mov DI, 0
    ;mov SI, offset arr
    ;mov DI, offset res
    mov DX, 5
    oloop:
        mov CX, 5
        lea DI, arr
        iloop:
            mov AL, [DI]
            cmp AL, [DI+1]
            jl common
            
            xchg AL, [DI+1]
            mov [DI], AL
            
            common:
                inc DI
        loop iloop
        
        dec DX
    jnz oloop
    
    mov SI, 0
    mov CX, 5
    mov AH, 2
    
    outputloop1:                   ; Iterate through arrNonPrime[] and print the 1s AX elements
    mov DL, arr[SI]
    add DL, 30h
    int 21h
    inc SI                         ; Print whitespace
    call printSpace
    loop outputloop1
    
    ;newline
    mov BL, AL
    mov AH, 09
    mov DX, offset linefeed
    int 21h
        
    ;print message
    mov DX, offset descsortmessage    ; Load Effective Address of the outputprompt in DX register
    lea DX, descsortmessage
    mov AH, 9
    int 21h
    
    mov SI, 4
    mov CX, 5
    mov AH, 2
    
    outputloop2:                   ; Iterate through arrNonPrime[] and print the 1s AX elements
    mov DL, arr[SI]
    add DL, 30h
    int 21h
    dec SI                         ; Print whitespace
    call printSpace
    loop outputloop2
    
main endp

ret

printSpace proc                    ; For printing spaces
    mov DL, ' '
    mov AH, 2
    int 21h
    ret
printSpace endp



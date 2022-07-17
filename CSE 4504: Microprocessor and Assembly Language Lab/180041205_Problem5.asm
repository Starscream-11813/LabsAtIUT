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
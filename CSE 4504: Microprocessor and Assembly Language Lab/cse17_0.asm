
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

.STACK 100h

.DATA
arr DB 5 DUP(?)
res DB 5 DUP(0)
inputprompt DB 'Input: $'
outputprompt DB 'Output: $'
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
    ;and AL, 0FH         ; Convert from ASCII value to actual value
    mov arr[SI], AL
    inc SI
    loop inputloop
    
    
    ;newline
    mov BL, AL
    mov AH, 09
    mov DX, offset linefeed
    int 21h
    
    ;print message
    mov DX, offset outputprompt    ; Load Effective Address of the outputprompt in DX register
    lea DX, outputprompt
    mov AH, 9
    int 21h
    
    mov SI, 4
    mov DI, 0
    ;mov SI, offset arr
    ;mov DI, offset res
    mov CX, 5
    
    iterationloop:
    
    mov BL, arr[SI]
    sub BL, 0020h
    mov res[DI], BL
    
    dec SI
    inc DI
    loop iterationloop
    
    mov CX, 5                     ; AX = Number of Non-Prime Numbers found
    mov SI, 0
    mov SI, offset res
    mov AH, 2
    
    outputloop1:                   ; Iterate through arrNonPrime[] and print the 1s AX elements
    mov DL, [SI]
    ;add DL, 30h
    int 21h
    inc SI                         ; Print whitespace
    ;call printSpace
    loop outputloop1

main endp

ret

;printSpace proc                    ; For printing spaces
;    mov DL, ' '
;    mov AH, 2
;    int 21h
;    ret
;printSpace endp



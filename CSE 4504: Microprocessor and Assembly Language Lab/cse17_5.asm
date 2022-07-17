
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

.STACK 100h

.DATA
NUM1 dw ?
arr dw 5 DUP(?)
inputprompt DB 'Input: $'
oddmessage DB 'Odd Digits: $'
summessage DB 'Sum: $'
averagemessage DB 'Average: $'
linefeed db 13, 10, "$"
sum dw 0
avg dw 0
count dw 0

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
    
    ;input
    mov AH, 1
	int 21h
	and AX, 0FH
	mov NUM1, AX
	
	mov CX, NUM1
	mov BX, 2
	mov SI, 0
	mov DX, 0
	
	iterationloop:
	div BX
	mov AX, CX
	cmp DX, 1
	je oddfound
	
	jmp bottom
	
	oddfound:
	mov arr[SI], AX
	inc SI
	add sum, AX
	add count, 1 
	
	bottom:
	xor DX, DX
	dec AX
	loop iterationloop
	
	;newline
    mov BL, AL
    mov AH, 09
    mov DX, offset linefeed
    int 21h
    
    ;print message
    mov DX, offset oddmessage    ; Load Effective Address of the primemessage in DX register
    lea DX, oddmessage
    mov AH, 9
    int 21h
    
    mov CX, count
    mov SI, 0
    mov AH, 2
    
    outputloop:                    ; Iterate through arrPrime[] and print the 1s AX elements
    mov DX, arr[SI]
    add DX, 30h
    int 21h
    inc SI
    call printSpace                ; Print whitespace
    loop outputloop
    
    ;newline
    mov BL, AL
    mov AH, 09
    mov DX, offset linefeed
    int 21h
    
    ;print message
    mov DX, offset summessage    ; Load Effective Address of the primemessage in DX register
    lea DX, summessage
    mov AH, 9
    int 21h
    
    ;print output stored in BL
    mov AH, 2
    mov DX, sum
    int 21h
    
    ;newline
    mov BL, AL
    mov AH, 09
    mov DX, offset linefeed
    int 21h
    
    ;print message
    mov DX, offset averagemessage    ; Load Effective Address of the primemessage in DX register
    lea DX, averagemessage
    mov AH, 9
    int 21h
    
    mov BX, count
    mov AX, sum
    div BL
    mov avg, AX
    add avg, 30h
    mov BX, avg
    
    
    ;print output stored in BL
    mov AH, 2
    mov DX, BX
    int 21h        
    
main endp

ret

printSpace proc                    ; For printing spaces
    mov DL, ' '
    mov AH, 2
    int 21h
    ret
printSpace endp



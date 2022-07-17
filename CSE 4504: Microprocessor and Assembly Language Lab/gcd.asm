org 100h

.STACK 100h

.DATA
  NUM1 DW ?
  NUM2 DW ?
  GCD DW ?
  inputprompt DB 'Input: $'
  gcdmessage DB 'GCD: $'
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
    
    ;input
    mov AH, 1
	int 21h
	mov NUM1, AX
	
	call printSpace
	
	;input
    mov AH, 1
	int 21h
    mov NUM2, AX
    
    mov AX,NUM1   ;Move the first number to AX.
    mov BX,NUM2   ;Move the second number to BX.
    
    top:
    cmp AX, BX
    je exit
    jb exchange
    
    top1:
    mov DX, 0
    div BX
    cmp DX, 0
    je exit
    mov AX, DX
    jmp top
    
    exchange:
    xchg AX, BX
    jmp top1
    
    exit:
    mov GCD, BX
    
    ;newline
    mov BL, AL
    mov AH, 09
    mov DX, offset linefeed
    int 21h
    
    ;print message
    mov DX, offset gcdmessage    ; Load Effective Address of the outputprompt in DX register
    lea DX, gcdmessage
    mov AH, 9
    int 21h
    
    ;print output stored in BL
    mov AH, 2
    mov DX, GCD
    add DX, 30h
    int 21h
    
main endp

ret

printSpace proc                    ; For printing spaces
    mov DL, ' '
    mov AH, 2
    int 21h
    ret
printSpace endp

; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

.DATA
prompt db 'Enter the value of N:$'
linefeed db 13, 10, "$"
sqSuffixSum  dw 10 dup(0)
N db 0
RESULT dw 0 
 
.CODE

main proc
    
    ;Prompt the user for input
    mov DX, offset prompt
    lea DX, prompt
    mov AH, 9
    int 21h
    
    ;input
    mov AH, 1
	int 21h
	
	
	mov CL, AL
    sub CL, 48  ;ASCII to number
    mov N, CL
    
    mov SI, OFFSET sqSuffixSum
    
    ;newline
    mov BL, AL
    mov AH, 09
    mov DX, offset linefeed
    int 21h
    
    loop1:
	
	;newline
    ;mov BL, AL
    ;mov AH, 09
    ;mov DX, offset linefeed
    ;int 21h
    
    mov AL, CL
    mul CL
    
    mov [SI], AL
    xor AL, AL
    
    inc SI
    ;add CL, 0030h
	;print
	;mov AH, 2
	;mov DL, CL
	;int 21h
	;sub CL, 0030h
	
	loop loop1
	
	mov DI, OFFSET sqSuffixSum
	mov CL, N
	
	xor BL, BL
	loop2:
	add BL, [DI]
	inc DI
	loop loop2
	
	add BL, 48
	
	mov AH, 2
    mov DL, BL
    int 21h
    
main endp
end main

ret





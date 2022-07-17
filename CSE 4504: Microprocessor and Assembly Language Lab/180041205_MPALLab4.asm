
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

.DATA
prompt db 'Given Character: $'
message db 'Number of Frequency: $'
linefeed db 13, 10, "$"
Input db 'Islamic University of Technology','$'

.CODE
main proc
    
    ;Display the Input string
    mov DX, offset Input
    lea DX, Input
    mov AH, 9
    int 21h
    
    ;newline
    mov BL, AL
    mov AH, 09
    mov DX, offset linefeed
    int 21h
    
    ;Prompt the user for input
    mov DX, offset prompt
    lea DX, prompt
    mov AH, 9
    int 21h
    
    ;input
    mov AH, 1
	int 21h
	
	;newline
    mov BL, AL
    mov AH, 09
    mov DX, offset linefeed
    int 21h
	
	mov AL, BL
	
	;print message
    mov DX, offset message    ; Load Effective Address of the message in DX register
    lea DX, message
    mov AH, 9
    int 21h
    
    mov AL, BL
                              
    mov SI, offset Input      ; Load Effective Address of the Input in SI register
    
    xor BL, BL                ; Clearing BL register (Will store the frequency)
    xor CL, CL                ; Clearing CL register (Will store the string length of Input)
    
    strlen:
    cmp [SI], '$'             ; Until '$' is reached
    je bottom
                              
    inc CL                    ; CL:=CL+1
    inc SI
    jmp strlen
    
    bottom:
    mov DI, offset Input      ; Load Effective Address of the Input in DI register
    
    frequencyLoop:            ; Loop and iterate through the characters
    cmp [DI], AL
    je equal
    inc DI
    jmp bottom2
    
    equal:
    inc BL                    ; If match found, BL:=BL+1
    inc DI
    
    bottom2:
    loop frequencyLoop
    
    add BL, 48                ; Convert the ASCII value of the output to decimal
    
    ;print output stored in BL
    mov AH, 2
    mov DL, BL
    int 21h 
		

main endp
end main

ret





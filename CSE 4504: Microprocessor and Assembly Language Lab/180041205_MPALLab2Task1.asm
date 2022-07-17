org 100h

linefeed db 13, 10, "$"

; add your code here
    
    ;takes a char as input
    mov AH, 1
    int 21h
    
    mov CL, 2
    div CL
    
    cmp AH, 01h       ;check if reminder is 1 or 0
    jl even_print     ;if 0, then the ASCII value is Even
    
    mov AL, 4Fh       ;else, it is Odd, so, assign the character 'O' to AL
    jmp bottom
    
    even_print:
    mov AL, 45h       ;assign the character 'E' to AL
    
    
    bottom:
    
    ;newline
    mov BL, AL
    mov AH, 09
    mov DX, offset linefeed
    int 21h
    
    ;prints the parity
    mov AH, 2
    mov DL, BL
    int 21h
    


ret





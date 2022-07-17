org 100h

linefeed db 13, 10, "$"

; add your code here
    
    ;takes a char as input
    mov AH, 1
    int 21h
    
    
    cmp AL, 61h
    jl uppercase_to_lowercase
    cmp AL, 61h
    jge lowercase_to_uppercase
    
    
    uppercase_to_lowercase:  
    add AL, 20h
    cmp AL, 7Ah
    jle bottom
    
    lowercase_to_uppercase:
    sub AL, 20h
    
    
    bottom:
    mov BL, AL
    mov AH, 09
    mov DX, offset linefeed
    int 21h
    ;prints the resized char
    mov AH, 2
    mov DL, BL
    int 21h
    


ret





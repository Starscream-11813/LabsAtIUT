
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

.data
test_string db 'We are IUT Students', 0Dh, 0Ah, '$'
idx dw 0
.code
main proc
    mov ah, 9
    lea dx, test_string
    int 21h
    mov ax, @DATA
    mov ds, ax
    xor cx, cx
    xor bl, bl
    ;mov bl, 1
;    
    mov cx, 50
;    mov ah, 2
;    mov dl, '*'
;    top:
;    int 21h
;    loop top
    top:
    ;inc cx
    cmp cx, 00FFFFh
    je exit
    
    mov si, offset test_string
    add si, idx
    inc idx
    mov bh, [si]
    cmp bh, '$'
    je exit
    
    cmp bh, ' '
    je space
    
    inc bl
    loop top
    
    space:
    inc bl
    loop top
    
    exit:
    ;sub bl, 2 
    mov ah, 4ch
    mov dl, bl
    int 21h
main endp
end main

ret





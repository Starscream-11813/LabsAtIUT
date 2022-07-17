org 100h

.STACK 100h

.DATA
arr DB 5 DUP(?)
arrPrime DB 5 DUP(0)
arrNonPrime DB 5 DUP(0) 
primemessage DB 'Prime: $'
nonprimemessage DB 'Non-prime: $'
inputprompt DB 'Input: $'
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
    mov DX, offset primemessage    ; Load Effective Address of the primemessage in DX register
    lea DX, primemessage
    mov AH, 9
    int 21h
    
    call Prime                     ; Filter the Prime Numbers
    
    mov CX, AX                     ; AX = Number of Prime Numbers found
    mov SI, 0
    mov AH, 2                      
    
    cmp CX, 00h
    je skip
    
    outputloop:                    ; Iterate through arrPrime[] and print the 1s AX elements
    mov DL, arrPrime[SI]
    add DL, 30h
    int 21h
    inc SI
    call printSpace                ; Print whitespace
    loop outputloop
    
    skip:
    
    ;newline
    mov BL, AL
    mov AH, 09
    mov DX, offset linefeed
    int 21h
    
    ;print message
    mov DX, offset nonprimemessage ; Load Effective Address of the nonprimemessage in DX register
    lea DX, nonprimemessage
    mov AH, 9
    int 21h
    
    call NonPrime                  ; Filter the Non-Prime Numbers
    
    mov CX, AX                     ; AX = Number of Non-Prime Numbers found
    mov SI, 0
    mov AH, 2                      
    
    cmp CX, 00h
    je skip1
    
    outputloop1:                   ; Iterate through arrNonPrime[] and print the 1s AX elements
    mov DL, arrNonPrime[SI]
    add DL, 30h
    int 21h
    inc SI                         ; Print whitespace
    call printSpace
    loop outputloop1
    
    skip1:
    
main endp
;end main

ret

Prime proc
    
    mov SI, 0
    mov DI, 0
    mov SI, offset arr
    mov DI, offset arrPrime
    mov CX, 5
    mov AX, 0
    
    iterationloop:                 ; Iterate through the elements and check if they are in [2, 3, 5, 7]
    
    cmp [SI], 02h
    je primefound
    
    cmp [SI], 03h
    je primefound
    
    cmp [SI], 05h
    je primefound
    
    cmp [SI], 07h
    je primefound
    
    jmp bottom
    
                                    
    primefound:                    ; If an element matches a Prime Number, then store it in arrPrime[]
    mov BL, [SI] 
    mov [DI], BL
    inc DI
    inc AX                         ; Increment the amount of Prime Numbers found
    
    bottom:
    inc SI
    
    loop iterationloop
    
    
    ret
Prime endp


NonPrime proc
    
    mov SI, 0
    mov DI, 0
    mov SI, offset arr
    mov DI, offset arrNonPrime
    mov CX, 5
    mov AX, 0
    
    iterationloop1:                ; Iterate through the elements and check if they are in [0, 1, 4, 6, 8, 9]
    
    cmp [SI], 00h
    je nonprimefound
    
    cmp [SI], 01h
    je nonprimefound
    
    cmp [SI], 04h
    je nonprimefound
    
    cmp [SI], 06h
    je nonprimefound
    
    cmp [SI], 08h
    je nonprimefound
    
    cmp [SI], 09h
    je nonprimefound
    
    jmp bottom1
    
    
    nonprimefound:                 ; If an element matches a Non-Prime Number, then store it in arrNonPrime[]
    mov BL, [SI] 
    mov [DI], BL
    inc DI
    inc AX                         ; Increment the amount of Non-Prime Numbers found
    
    bottom1:
    inc SI
    
    loop iterationloop1
    
    ret
NonPrime endp

printSpace proc                    ; For printing spaces
    mov DL, ' '
    mov AH, 2
    int 21h
    ret
printSpace endp    
        
    
    
    
    
    
  



    



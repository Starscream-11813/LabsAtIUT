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
	
	;newline
	mov BL, AL
	mov AH, 09
	mov DX, offset linefeed
	int 21h
	
	;prints the resized char + 1
	;mov AH, 2
	;mov DL, BL
	;int 21h
	
	mov CX, 5
	
forward_loop_start:
	add BL, 01h
	cmp BL, 7Bh
	jge lowercase_wraparound1
	cmp BL, 61h
	jge forward_loop_end
	cmp BL, 5Bh
	jge uppercase_wraparound1
	jmp forward_loop_end
	
uppercase_wraparound1:
	sub BL, 1Ah
	cmp BL, 7Ah
	jle forward_loop_end
	
	
lowercase_wraparound1:
	sub BL, 1Ah
	
	
forward_loop_end:
	
	;prints the resized char + 1
	mov AH, 2
	mov DL, BL
	int 21h
	
	loop forward_loop_start
	
	
	;newline
	mov BL, AL
	mov AH, 09
	mov DX, offset linefeed
	int 21h
	
	mov CX, 5
	
	sub BL, 05h
backward_loop_start:
	sub BL, 01h
	cmp BL, 40h
	jle uppercase_wraparound2
	cmp BL, 5Ah
	jle backward_loop_end
	cmp BL, 60h
	jle lowercase_wraparound2
	jmp backward_loop_end
	
uppercase_wraparound2:
	add BL, 1Ah
	cmp BL, 41h
	jge backward_loop_end
	
	
lowercase_wraparound2:
	add BL, 1Ah
	
	
backward_loop_end:
	
	;prints the resized char - 1
	mov AH, 2
	mov DL, BL
	int 21h
	
	loop backward_loop_start
	
	
	
	ret

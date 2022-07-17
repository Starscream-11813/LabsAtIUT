DATA SEGMENT
    ;MSG1 DB 10,13,'ENTER ANY STRING :- $'
    MSG2 DB 10,13,'$'
    MSG3 DB 10,13,'$'
   
    P1 LABEL BYTE
    M1 DB 0FFH
    L1 DB ?
    P11 DB 0FFH DUP ('$')
DATA ENDS
DISPLAY MACRO MSG
    MOV AH,9
    LEA DX,MSG
    INT 21H
ENDM  
CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
START:
        MOV AX,DATA
        MOV DS,AX                
               
        ;DISPLAY MSG1
       
        LEA DX,P1
        MOV AH,0AH    
        INT 21H
       
        DISPLAY MSG2
       
        DISPLAY P11
                   
        DISPLAY MSG3
               
        LEA SI,P11
              
        MOV CL,L1
        MOV CH,0       
CHECK:
        CMP [SI],41H
        JB DONE
       
        CMP [SI],5BH
        JB LWR
       
        CMP [SI],61H
        JB DONE
       
        CMP [SI],7BH
        JG DONE
       
UPR:    SUB [SI],20H
        JMP DONE
LWR:    ADD [SI],20H
            
DONE:   INC SI
        LOOP CHECK
               
        DISPLAY P11
                               
        MOV AH,4CH
        INT 21H
CODE ENDS
END START
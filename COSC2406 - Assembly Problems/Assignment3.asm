sort PROC
; esi -- array
; ecx -- size
    xor eax, eax    ; i
    mov edi, ecx    
    dec edi         ; size-1
for01:
    cmp eax, edi
    jnl endfor01
; int min = i 
    mov ebx, eax    ;min 
for (j = i+1; j < size; ++j) {
    mov edx, eax    ; j
    inc edx
for02:
    cmp edx, ecx 
    jnl endfor02
; if (array[j] < array [min]) {
    mov ebp, [esi+edx*4]
    cmp ebp, [esi+ebx*4]
    jnl endif01
; min = j;
    mov ebx, edx
; }
endif01:
; }
    inc edx
    jmp for02 
endfor02:
; if(min != i) { 
    cmp ebx, eax
    je endif02
; int temp = array[i];
    mov ebp, [esi+eax*4]
; array[i] = array[min];
    xchg ebp, [esi+ebx*4]
; array[min] = temp;
; . . . he moved to fast to type it 
}




isFloatingPoint PROC

; esi -- string
    push eax
    push esi

StateA:
    mov al, [esi]
    call isDigit
    je StateC
    cmp al, '+'
    je StateB
    cmp al, '-'
    je StateB
    jmp ErrorState

StateB:
    inc esi
    mov al, [esi]
    call isDigit
    je StateC
    jmp ErrorState

StateC:
    inc esi
    mov al, [esi]
    cmp al, 0
    je ValidState
    cmp al, '.'
    je StateD
    jmp ErrorState

StateD:
    inc esi
    mov al, [esi]
    cmp al, 0
    je ValidState
    call isDigit
    je StateD
    jmp ErrorState

ErrorState:
ValidState:
EndState:
    pop esi
    pop eax
    ret

isFloatingPoint ENDP




; #7 - FSM Question

FSM PROC
    ; esi -- string
StateA:
    mov     al, [esi]
    cmp     al, '0'
    jnae    errorState
    cmp al, '8'
    jnbe    errorState 

StateB:
    inc     esi 
    mov     al, [esi] 
    cmp     al, 'q'
    je      StateC
    cmp     al, 'Q'
    je      StateC
    cmp     al, 'o'
    je      StateC
    cmp     al, 'O'
    je      StateC
    cmp     al, '0'
    jnae    errorState
    cmp     al, '8'
    jnbe    errorState
    jmp     StateB

StateC: 
    inc     esi
    mov     al, [esi]
    cmp     al, 0
    jne     errorState 
    jmp     return

errorState:
    mov     al, 0
    cmp     al, 1

return:
    ret
    
FSM ENDP
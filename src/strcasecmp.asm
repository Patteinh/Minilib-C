bits 64
section .text
    global strcasecmp

strcasecmp:                     ; int strcasecmp(const char *, const char *)
    mov rcx, 0                  ; rcx = 0
    mov r8, rdi                 ; copy the address of the first string to r8
    mov r9, rax                 ; store the res in r9
    mov rdx, rax                ; store the res in rdx
    cmp r9, 0                   ; r9 == 0 ?
    je end_1                    ; if equal, jump to end_1
    cmp rdx, 0                  ; rdx == 0 ?
    je end_1                    ; if equal, jump to end_1

loop:
    movzx rdi, byte [r8 + rcx]	; load the cur char of first string into rdi (zero-extend it)
    call ismaj			        ; call ismaj check if the char is an upper letter
    mov r9, rax			        ; store the res in r9
    movzx rdi, byte [rsi + rcx]	; load the cur char of second string into rdi and (zero-extend it)
    call ismaj			        ; call ismaj check if the char is an upper letter
    mov rdx, rax		        ; store the res in rdx
    jmp compare_check           ; jump compare_check function

compare_check:
    cmp r9, 0			        ; r9 == 0 ?
    je end_1			        ; if equal, jump to end_1
    cmp rdx, 0			        ; rdx == 0 ?
    je end_1			        ; if equal, jump to end_1
    cmp rdx, r9			        ; rdx == r9 ?
    jne end_1			        ; if not equal, jump to end_1
    inc rcx			            ; inc the idx into the strings
    jmp loop                    ; repeat loop

end_1:
    sub r9, rdx			        ; subtract the value in rdx from the value in r9
    mov rax, r9			        ; store the res in rax
    ret				            ; return rax

ismaj:
    cmp rdi, 'A'		        ; rdi == 'A' ?
    jge maj			            ; if >=, jump to maj
    jmp end_2			        ; otherwise, jump to end_2

maj:
    cmp rdi, 'Z'		        ; rdi == 'Z' ?
    jle low			            ; if <=, jump to low
    jmp end_2	        	    ; otherwise, jump to end_2

low:
    add rdi, 'a' - 'A'		    ; add the difference between the lower and upper letters to rdi
    jmp end_2			        ; jump to end_2

end_2:
    mov rax, rdi	            ; store rdi in rax
    ret				            ; return rax

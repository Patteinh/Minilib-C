bits 64
section .text
    global strcmp

strcmp:                     ; int strcmp(const char *, const char *);
    xor rax, rax            ; rax = 0
    xor rcx, rcx            ; rcx = 0

loop:
    cmp byte [rsi], 0       ; cur char in second string == 0 ?
    je end                  ; if equal, jump to end
    mov r8b, byte [rsi]     ; move cur char in second string to r8b
    cmp byte [rdi], r8b     ; cur char in first string == r8b ?
    jne end                 ; if not equal, jump to end
    inc rsi                 ; inc idx in second string
    inc rdi                 ; inc idx in first string
    jmp loop                ; repeat the loop

end:
    mov al, [rdi]           ; move cur char in first string to al
    mov cl, [rsi]           ; move cur char in second string to cl
    sub rax, rcx            ; subtract rcx from rax
    ret                     ; return rax

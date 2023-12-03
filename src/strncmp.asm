bits 64
section .text
    global strncmp

strncmp:                ; int strncmp(const char *, const char *, size_t);
    xor rax, rax        ; rax = 0
    xor rcx, rcx        ; rcx = 0

loop:
    cmp byte [rsi], 0   ; cur char second str == 0 ?
    je end              ; if equal, jump to end
    dec rdx             ; decrement n
    jz end              ; if n == 0, jump to end
    mov r8b, byte [rsi] ; move cur char in second str to r8b
    cmp byte [rdi], r8b ; cur char in first str == r8b ?
    jne end             ; if not equal, jump to end
    inc rsi             ; inc idx in second str
    inc rdi             ; inc idx in first str
    jmp loop            ; repeat the loop

end:
    mov al, [rdi]       ; move cur char in first str to al
    mov cl, [rsi]       ; move cur char in second str to cl
    sub rax, rcx        ; subtract rcx from rax
    ret                 ; return rax

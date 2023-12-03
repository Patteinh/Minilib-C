bits 64
section .text
    global strlen

strlen:                         ; size_t my_strlen(const char *);
    xor rax, rax                ; rax = 0

loop:
    cmp byte [rax + rdi], 0     ; cur char == 0 ?
    je end                      ; if equal, jump to end
    inc rax                     ; inc counter
    jmp loop                    ; repeat the loop

end:
    ret                         ; return rax

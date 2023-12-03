bits 64
section .text
    global strchr

strchr:                     ; char * strchr(const char *, int);
    xor rax, rax            ; rax = 0

loop:
    cmp byte [rdi], sil     ; cur char in the string == given char ?
    je end                  ; if equal, jump to end
    cmp byte [rdi], 0       ; cur char == '\0'
    je end_0                ; if '\0', jump to end_0
    inc rdi                 ; inc to the next char
    jmp loop                ; repeat the loop

end_0:
    mov rax, 0              ; rax = 0
    ret                     ; return rax

end:
    mov rax, rdi            ; set the return value to the address of the char
    ret                     ; return rax

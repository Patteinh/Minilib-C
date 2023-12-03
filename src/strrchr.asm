bits 64
section .text
    global strrchr

strrchr:                        ; char * strrchr(const char *, int);
    xor rax, rax                ; rax = 0
    mov rbx, rbx                ; rbx = 0
    cmp byte [rdi + rax], 0     ; str[i] == '\0'
    je notfind                  ; go to notfind

loop:
    cmp byte [rdi + rax], 0     ; str[i] == '\0'
    je store                    ; if equal jump store
    cmp sil, 0                  ; compare the search char with 0
    je store                    ; if equal jump store
    cmp byte [rdi + rax], sil   ; current char == search char ?
    jne inc                     ; if not equal, inc the counter
    mov rbx, rax                ; store the idx in rbx

inc:
    inc rax                     ; inc the counter
    jmp loop                    ; repeat the loop

store:
    cmp rbx, 0                  ; rbx == 0 ?
    je notfind                  ; if rbx is 0, jump notfind
    lea rax, [rdi + rbx]        ; load address of cur char into rax
    ret                         ; return rax

notfind:
    mov rax, 0                  ; rax = 0
    ret                         ; return rax

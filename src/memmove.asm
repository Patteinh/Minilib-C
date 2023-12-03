bits 64
section .text
    global memmove

memmove:            ; void * memmove(void *, const void *, size_t);
    mov rax, rdi    ; move the dest address to rax
    cmp rdi, rsi    ; compare the dest and src address
    je end          ; if equal, jump to end
    jb fast         ; if the dest lower than src, jump to fast

slow:
    std             ; set direction flag to decrement (reverse copy)
    mov rcx, rdx    ; move the length to rcx
    dec rdx         ; decrement the length
    add rsi, rdx    ; move the src ptr to end of data
    add rdi, rdx    ; move the dest ptr to end of data
    rep movsb       ; move 1 byte from src to dest
    cld             ; clear the direction flag
    ret             ; return rax

fast:
    mov rcx, rdx    ; move the length to rcx
    rep movsb       ; move 1 byte from src to dest

end:
    ret             ; return rax

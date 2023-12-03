bits 64
section .text
    global memcpy

memcpy:             ; void * memcpy(void *, const void *, size_t);
    mov rax, rdi    ; move the dest address to rax
    mov rcx, rdx    ; move the length to rcx

loop:
    cmp rcx, 0      ; compare the length to 0
    je end          ; if length is 0, jump to end
    mov r8b, [rsi]  ; moving 1 byte into the low 8 bits of the r8 register
    mov [rdi], r8b  ; store the value in r8 at the dest address
    inc rdi         ; inc the dest address
    inc rsi         ; inc the src address
    dec rcx         ; decrement the length
    jmp loop        ; repeat the loop

end:
    ret             ; return rax

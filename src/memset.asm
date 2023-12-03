bits 64
section .text
    global memset

memset:                     ; void *memset(void *, int, size_t);
    xor rcx, rcx            ; rcx = 0
    mov rax, rdi            ; move dest address to rax

loop:
    cmp rcx, rdx            ; compare count with length
    je end                  ; if equal jump to end
    mov [rax + rcx], sil    ; store value in dest
    inc rcx                 ; inc counter
    jmp loop                ; repeat loop

end:
    ret                     ; return rax

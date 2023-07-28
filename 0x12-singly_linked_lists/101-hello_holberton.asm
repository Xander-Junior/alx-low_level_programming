section .data
    msg db "Hello, Holberton", 0Ah  ; 0Ah is the ASCII code for newline
    l equ $ - msg                   ; l is the length of the message

section .text
    global main

main:
    mov rax, 1      ; syscall number for sys_write
    mov rdi, 1      ; file descriptor 1 (stdout)
    mov rsi, msg    ; pointer to the string
    mov rdx, l      ; string length
    syscall

    mov rax, 60     ; syscall number for sys_exit
    xor rdi, rdi    ; exit status 0
    syscall

end:

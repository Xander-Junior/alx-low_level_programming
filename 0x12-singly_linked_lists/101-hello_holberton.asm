section .data
    hello db 'Hello, Holberton', 0

section .text
    extern printf, exit

global main
main:
    ; Prepare arguments to call printf
    lea rdi, [hello]  ; Load address of hello string into rdi
    call printf

    ; Exit the program
    xor edi, edi        ; status: 0
    call exit

section .data
    text1 db "What is your name? "
    text2 db "Hello, "

section .bss
    name resb 16

section .text
    global _start
_start:

    mov rcx, text1
    call _printText
    call _getName
    mov rcx, text2
    call _printText

    mov rax, 60
    mov rdi, 0
    syscall

_getName:
    mov rax, 0
    mov rdi, 0
    mov rsi, name
    mov rdx, 10
    syscall
    ret

_printText:
    mov rax, 1
    mov rdi, 1
    mov rsi, rcx
    mov rdx, 19
    syscall
    ret
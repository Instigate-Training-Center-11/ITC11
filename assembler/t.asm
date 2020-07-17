%include "header.inc"
section .data
    newline db "",10,0

section .text
    global _start

_start:
    pop rcx
    pop rax
    pop rax
    push rax
    print rax
    print newline
    pop rax
    printVal rax
    exit
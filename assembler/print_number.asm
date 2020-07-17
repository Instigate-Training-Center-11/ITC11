%include "header.inc"

section .bss
    digitSpace resb 100
    digitSpacePos resb 8

section .text
    global _start

_start:

    mov rax, 1994

    divideNumberOfParts digitSpace, digitSpacePos
    numberAddAsciiCode digitSpacePos
    printNumber digitSpacePos, digitSpace
    exitCall
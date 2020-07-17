; Calculator (ATOI)
; Compile with: nasm -f elf calculator-atoi.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 calculator-atoi.o -o calculator-atoi
; Run with: ./calculator-atoi 20 1000 317

%include        'common.inc'
%include        'functions.asm'

; section .data
;     text db "arg[1] + arg[2] = ",0x30,0

; section .bss
;     digitSpace resb 100
;     digitSpacePos resb 8
;     printSpace resb 8

section .text
    global  _start

_start:
    pop     ecx             ; first value on the stack is the number of arguments
    pop     edx             ; second value on the stack is the program name (discarded when we initialise edx)
    sub     ecx, 1          ; decrease ecx by 1 (number of arguments without program name)
    mov     edx, 0          ; initialise our data register to store additions
    pop     eax             ; pop the next argument off the stack
    call    atoi            ; convert our ascii string to decimal integer
    mov     edx, eax        ; perform our addition logic
    pop     eax             ; pop the next argument off the stack
    call    atoi            ; convert our ascii string to decimal integer
    call    iprintLF        ; call our integer printing with linefeed function



    noMoreArgs:
    mov     eax, edx        ; move our data result into eax for printing
    call    iprintLF        ; call our integer printing with linefeed function
    call    quit            ; call our quit function
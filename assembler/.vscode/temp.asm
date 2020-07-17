SYS_EXIT  equ 1
SYS_READ equ 0
SYS_WRITE equ 4
STDIN     equ 0
STDOUT    equ 1


%macro writeString 2
    mov   eax, SYS_WRITE
    mov   ebx, STDOUT
    mov   ecx, %1
    mov   edx, %2
    syscall
    ret
%endmacro

%macro readString 2
    mov   eax, SYS_READ
    mov   ebx, STDIN
    mov   ecx, %1
    mov   edx, %2
    syscall
    ret
%endmacro
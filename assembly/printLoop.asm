section .data
	string db "What is your name? ",0
	answer db "Hello, "

section .bss
	name resb 20

section .text
	global _start

_start:
	mov rax, string
	call _print

	call _getName
	
	mov rax, answer
	call _print
	mov rax, name
	call _print

	mov rax, 60
	mov rdi, 0
	syscall

_print:
	push rax ;set in stack
	mov rbx, 0 ;symbol count

_loop:
	inc rax ;increment by 1
	inc rbx ;increment by 1
	mov cl, [rax]
	cmp cl, 0 ;if not end of line
	jne _loop

	;print string
	mov rax, 1
	mov rdi, 1
	pop rsi ;get from stack
	mov rdx, rbx
	syscall
	ret

_getName:
        mov rax, 0
        mov rdi, 0
        mov rsi, name
        mov rdx, 20
        syscall
        ret


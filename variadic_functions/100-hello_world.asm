global main

section .text

main:
	mov rax, 1
	mov rdi, 1
	mov rsi, message
	mov rdx, message_len
	syscall
	mov rax, 0
	ret

section .data
message: db "Hello, World", 10
message_len: equ $ - message

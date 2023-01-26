section .data
	msg: db "Hello, Holberton",0xa,0
	fmt: db "%s", 0
	
section .text
	default rel
	extern printf
	global main

main:
	push rbp
	mov rdi, fmt
	mov rsi, msg
	mov rax, 0
	call printf
	pop rbp
	mov rax, 0
	ret

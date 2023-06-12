global _main
extern _printf

section .text
_main:
	push rbp
	mov rdi, msg
	mov rsi, meta
	mov rdx, meta
	call _printf
	pop rbp
	ret

section .data
	msg: db "global _main", 10, "extern _printf", 10, 10, "section .text", 10, "_main:", 10, 9, "push rbp", 10, 9, "mov rdi, msg", 10, 9, "mov rsi, meta", 10, 9, "mov rdx, meta", 10, 9, "call _printf", 10, 9, "pop rbp", 10, 9, "ret", 10, 10, "section .data", 10, 9, "msg: db ", 34, 37, 115, 10, 9, "meta: db ", 39, 37, 115, 39, 0
	meta: db 'global _main", 10, "extern _printf", 10, 10, "section .text", 10, "_main:", 10, 9, "push rbp", 10, 9, "mov rdi, msg", 10, 9, "mov rsi, meta", 10, 9, "mov rdx, meta", 10, 9, "call _printf", 10, 9, "pop rbp", 10, 9, "ret", 10, 10, "section .data", 10, 9, "msg: db ", 34, 37, 115, 10, 9, "meta: db ", 39, 37, 115, 39, 0'
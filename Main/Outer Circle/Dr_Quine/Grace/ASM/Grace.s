extern _fopen
extern _fprintf
extern _fclose
; This program will print its own source when run.
%macro _macro 0
	push rbp
	mov rdi, source
	mov rsi, arg
	call _fopen
	test rax, rax
	jz _err
	mov rbp, rax
	mov rdi, rax
	mov rsi, msg
	mov rdx, meta
	mov rcx, meta
	call _fprintf
	mov rdi, rbp
	call _fclose
	pop rbp
	ret
_err:
	pop rbp
	ret
%endmacro

section .text
	global _main
_main:
	_macro

section .data
	msg: db "extern _fopen", 10, "extern _fprintf", 10, "extern _fclose", 10, "; This program will print its own source when run.", 10, "%%macro _macro 0", 10, 9, "push rbp", 10, 9, "mov rdi, source", 10, 9, "mov rsi, arg", 10, 9, "call _fopen", 10, 9, "test rax, rax", 10, 9, "jz _err", 10, 9, "mov rbp, rax", 10, 9, "mov rdi, rax", 10, 9, "mov rsi, msg", 10, 9, "mov rdx, meta", 10, 9, "mov rcx, meta", 10, 9, "call _fprintf", 10, 9, "mov rdi, rbp", 10, 9, "call _fclose", 10, 9, "pop rbp", 10, 9, "ret", 10, "_err:", 10, 9, "pop rbp", 10, 9, "ret", 10, "%%endmacro", 10, 10, "section .text", 10, 9, "global _main", 10, "_main:", 10, 9, "_macro", 10, 10, "section .data", 10, 9, "msg: db ", 34, 37, 115, 10, 9, "meta: db ", 39, 37, 115, 39, ", 0", 10, 9, "source: db ", 34, "Grace_kid.s", 34, ", 0", 10, 9, "arg: db ", 34, "w", 34, ", 0", 0
	meta: db 'extern _fopen", 10, "extern _fprintf", 10, "extern _fclose", 10, "; This program will print its own source when run.", 10, "%%macro _macro 0", 10, 9, "push rbp", 10, 9, "mov rdi, source", 10, 9, "mov rsi, arg", 10, 9, "call _fopen", 10, 9, "test rax, rax", 10, 9, "jz _err", 10, 9, "mov rbp, rax", 10, 9, "mov rdi, rax", 10, 9, "mov rsi, msg", 10, 9, "mov rdx, meta", 10, 9, "mov rcx, meta", 10, 9, "call _fprintf", 10, 9, "mov rdi, rbp", 10, 9, "call _fclose", 10, 9, "pop rbp", 10, 9, "ret", 10, "_err:", 10, 9, "pop rbp", 10, 9, "ret", 10, "%%endmacro", 10, 10, "section .text", 10, 9, "global _main", 10, "_main:", 10, 9, "_macro", 10, 10, "section .data", 10, 9, "msg: db ", 34, 37, 115, 10, 9, "meta: db ", 39, 37, 115, 39, ", 0", 10, 9, "source: db ", 34, "Grace_kid.s", 34, ", 0", 10, 9, "arg: db ", 34, "w", 34, ", 0", 0', 0
	source: db "Grace_kid.s", 0
	arg: db "w", 0
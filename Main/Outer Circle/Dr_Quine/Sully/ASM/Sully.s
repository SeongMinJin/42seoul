extern _fopen
extern _fprintf
extern _fclose
extern _sprintf
extern _strcmp
extern _bzero
extern _system

section .text
	global _main

_main:
	push rbp
	mov rbp, 5
	cmp rbp, 1
	jc _done

	mov rdi, source
	mov rsi, 20
	call _bzero
	mov rsi, sourceF
	mov rdx, rbp
	call _sprintf

	mov rdi, source
	mov rsi, original
	call _strcmp
	test rax, rax
	jz _equal

_not_equal:
	dec rbp

_equal:
	mov rdi, object
	mov rsi, 20
	call _bzero
	mov rsi, objectF
	mov rdx, rbp
	call _sprintf

	mov rdi, execute
	mov rsi, 20
	call _bzero
	mov rsi, executeF
	mov rdx, rbp
	call _sprintf

	mov rdi, compile
	mov rsi, 100
	call _bzero
	mov rsi, compileF
	mov rdx, source
	mov rcx, object
	mov r8, object
	mov r9, execute
	call _sprintf

	mov rdi, cmd
	mov rsi, 20
	call _bzero
	mov rsi, cmdF
	mov rdx, execute
	call _sprintf

	mov rdi, source
	mov rsi, arg
	call _fopen

	test rax, rax
	jz _done

	sub rsp, 8
	push rax
	mov rdi, rax
	mov rsi, msg
	mov rdx, meta
	call _fprintf

	pop rdi
	add rsp, 8
	call _fclose

	mov rdi, compile
	call _system

	cmp rbp, 0
	jz _done
	mov rdi, cmd
	call _system

_done:
	xor rax, rax
	pop rbp
	ret

section .data
	original: db "Sully.s", 0
	sourceF: db "Sully_%d.s", 0
	objectF: db "Sully_%d.o", 0
	executeF: db "Sully_%d", 0
	compileF: db "nasm -f macho64 %s -o %s; ld -lSystem %s -o %s", 0
	cmdF: db "./%s", 0
	arg: db "w", 0
	msg: db "extern _fopen", 10, "extern _fprintf", 10, "extern _fclose", 10, "extern _sprintf", 10, "extern _strcmp", 10, "extern _bzero", 10, "extern _system", 10, 10, "section .text", 10, 9, "global _main", 10, 10, "_main:", 10, 9, "push rbp", 10, 9, "mov rbp, ", 37, 100, 10, 9, "cmp rbp, 1", 10, 9, "jc _done", 10, 10, 9, "mov rdi, source", 10, 9, "mov rsi, 20", 10, 9, "call _bzero", 10, 9, "mov rsi, sourceF", 10, 9, "mov rdx, rbp", 10, 9, "call _sprintf", 10, 10, 9, "mov rdi, source", 10, 9, "mov rsi, original", 10, 9 , "call _strcmp", 10, 9, "test rax, rax", 10, 9, "jz _equal", 10, 10, "_not _equal:", 10, 9, "dec rbp", 10, 10, "_equal:", 10, 9, "mov rdi, object", 10, 9, "mov rsi, 20", 10, 9, "call _bzero", 10, 9, "mov rsi, objectF", 10, 9, "mov, rdx, rbp", 10, 9, "call _sprintf", 10, 10, 9, "mov rdi, execute", 10, 9, "mov rsi, 20", 10, 9, "call _bzero", 10, 9, "mov rsi, executeF", 10, 9, "mov rdx, rbp", 10, 9, "call _sprintf", 10, 10, 9, "mov rdi, compile", 10, 9, "mov rsi, 100", 10, 9, "call _bzero", 10, 9, "mov rsi, compileF", 10, 9, "mov rdx, source", 10, 9, "mov rcx, object", 10, 9, "mov r8, object", 10, 9, "mov r9, execute", 10, 9, "call _sprintf", 10, 10, 9, "mov rdi, cmd", 10, 9, "mov rsi, 20", 10, 9, "call _bzero", 10, 9, "mov rsi, cmdF", 10, 9, "mov rdx, execute", 10, 9, "call _sprintf", 10, 10, 9, "mov rdi, source", 10, 9, "mov rsi, arg", 10, 9, "call _fopen", 10, 10, 9, "text rax, rax", 10, 9, "jz _done", 10, 10, 9, "sub rsp, 8", 10, 9, "push rax", 10, 9, "mov rdi, rax", 10, 9, "mov rsi, msg", 10, 9, "mov rdx, meta", 10, 9, "call _fprintf", 10, 10, 9, "pop rdi", 10, 9, "add rsp, 8", 10, 9, "call _fclose", 10, 10, 9, "mov rdi, compile", 10, 9, "call _system", 10, 10, 9, "cmp rbp, 0", 10, 9, "jz _done", 10, 9, "mov rdi, cmd", 10, 9, "call _system", 10, 10, "_done:", 10, 9, "xor rax, rax", 10, 9, "pop rbp", 10, 9, "ret", 10, 10, "section .data", 10, 9, "original: db", 34, "Sully.s", 34, ", 0", 10, 9, "sourceF: db ", 34, "Sully_%%d.s", 34, ", 0", 10, 9, "objectF: db ", 34, "Sully_%%d.o", 34, ", 0", 10, 9, "executeF: db ", 34, "Sully_%%d", 34, ", 0", 10, 9, "compileF: db ", 34, "nasm -f macho64 %%s -o %%s; ld -lSystem %%s -o %%s", 34, ", 0", 10, 9, "cmdF: db ", 34, "./%%s", 34, ", 0", 10, 9, "arg: db ", 34, "w", 34, ", 0", 10, 9, "msg: db ", 34, 37, 115, ", 0", 10, 9, "meta: db ", 39, 37, 115, ", 0", 10, 10, "section .bss", 10, 9, "source: resb 20", 10, 9, "object: resb 20", 10, 9, "execute: resb 20", 10, 9, "compile: resb 100", 10, 9, "cmd: resb 20", 0
	meta: db 'extern _fopen", 10, "extern _fprintf", 10, "extern _fclose", 10, "extern _sprintf", 10, "extern _strcmp", 10, "extern _bzero", 10, "extern _system", 10, 10, "section .text", 10, 9, "global _main", 10, 10, "_main:", 10, 9, "push rbp", 10, 9, "mov rbp, ", 37, 100, 10, 9, "cmp rbp, 1", 10, 9, "jc _done", 10, 10, 9, "mov rdi, source", 10, 9, "mov rsi, 20", 10, 9, "call _bzero", 10, 9, "mov rsi, sourceF", 10, 9, "mov rdx, rbp", 10, 9, "call _sprintf", 10, 10, 9, "mov rdi, source", 10, 9, "mov rsi, original", 10, 9 , "call _strcmp", 10, 9, "test rax, rax", 10, 9, "jz _equal", 10, 10, "_not _equal:", 10, 9, "dec rbp", 10, 10, "_equal:", 10, 9, "mov rdi, object", 10, 9, "mov rsi, 20", 10, 9, "call _bzero", 10, 9, "mov rsi, objectF", 10, 9, "mov, rdx, rbp", 10, 9, "call _sprintf", 10, 10, 9, "mov rdi, execute", 10, 9, "mov rsi, 20", 10, 9, "call _bzero", 10, 9, "mov rsi, executeF", 10, 9, "mov rdx, rbp", 10, 9, "call _sprintf", 10, 10, 9, "mov rdi, compile", 10, 9, "mov rsi, 100", 10, 9, "call _bzero", 10, 9, "mov rsi, compileF", 10, 9, "mov rdx, source", 10, 9, "mov rcx, object", 10, 9, "mov r8, object", 10, 9, "mov r9, execute", 10, 9, "call _sprintf", 10, 10, 9, "mov rdi, cmd", 10, 9, "mov rsi, 20", 10, 9, "call _bzero", 10, 9, "mov rsi, cmdF", 10, 9, "mov rdx, execute", 10, 9, "call _sprintf", 10, 10, 9, "mov rdi, source", 10, 9, "mov rsi, arg", 10, 9, "call _fopen", 10, 10, 9, "text rax, rax", 10, 9, "jz _done", 10, 10, 9, "sub rsp, 8", 10, 9, "push rax", 10, 9, "mov rdi, rax", 10, 9, "mov rsi, msg", 10, 9, "mov rdx, meta", 10, 9, "call _fprintf", 10, 10, 9, "pop rdi", 10, 9, "add rsp, 8", 10, 9, "call _fclose", 10, 10, 9, "mov rdi, compile", 10, 9, "call _system", 10, 10, 9, "cmp rbp, 0", 10, 9, "jz _done", 10, 9, "mov rdi, cmd", 10, 9, "call _system", 10, 10, "_done:", 10, 9, "xor rax, rax", 10, 9, "pop rbp", 10, 9, "ret", 10, 10, "section .data", 10, 9, "original: db", 34, "Sully.s", 34, ", 0", 10, 9, "sourceF: db ", 34, "Sully_%%d.s", 34, ", 0", 10, 9, "objectF: db ", 34, "Sully_%%d.o", 34, ", 0", 10, 9, "executeF: db ", 34, "Sully_%%d", 34, ", 0", 10, 9, "compileF: db ", 34, "nasm -f macho64 %%s -o %%s; ld -lSystem %%s -o %%s", 34, ", 0", 10, 9, "cmdF: db ", 34, "./%%s", 34, ", 0", 10, 9, "arg: db ", 34, "w", 34, ", 0", 10, 9, "msg: db ", 34, 37, 115, ", 0", 10, 9, "meta: db ", 39', 37, 115, ", 0", 10, 10, "section .bss", 10, 9, "source: resb 20", 10, 9, "object: resb 20", 10, 9, "execute: resb 20", 10, 9, "compile: resb 100", 10, 9, "cmd: resb 20", 0

section .bss
	source: resb 20
	object: resb 20
	execute: resb 20
	compile: resb 100
	cmd: resb 20
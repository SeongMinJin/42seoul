global _ft_strdup
extern _malloc
extern _ft_strlen


section .text

_ft_strdup:
	push rdi ; save parameter
	call _ft_strlen

	mov rdi, rax ; mov ft_strlen return value to rdi to call malloc
	inc rdi
	call _malloc 

	test rax, rax
	jz .error ; null guard

	; currently  rax <- ptr of new str,   rdi <- length of str + 1

	mov rsi, rdi ; copy length to rsi
	pop rdi ; restore parameter
	push rax ; save head ptr of new str

.loop:
	mov dl, [rdi]
	test dl, dl
	jz .done

	mov [rax], dl

	inc rax
	inc rdi
	jmp .loop

.done:
	mov byte [rax], 0x0
	pop rax
	ret

.error:
	pop rdi
	ret
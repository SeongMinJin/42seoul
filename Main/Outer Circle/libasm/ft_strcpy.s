global _ft_strcpy

section .text
_ft_strcpy:
	mov rax, rdi

.loop:
	mov dl, [rsi]
	mov [rdi], dl

	inc rdi
	inc rsi
	test dl, dl

	jnz .loop

.done:
	ret

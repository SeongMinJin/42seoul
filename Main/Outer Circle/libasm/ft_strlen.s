global _ft_strlen

section .text
_ft_strlen:
	xor rax, rax

.loop:
	mov sil, [rdi]
	test sil, sil
	jz .done

	inc rax
	inc rdi
	jmp .loop

.done:
	ret
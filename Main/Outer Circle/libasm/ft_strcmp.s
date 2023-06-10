global _ft_strcmp

section .text

_ft_strcmp:
	xor rax, rax ; clean all bits to `zero`
	xor rdx, rdx 

.loop:
	mov al, [rdi]
	mov dl, [rsi]

	or al, dl
	jz .done ;jump to .done if both of value are `null`

	mov al, [rdi]
	sub eax, edx
	jnz .done ;jum to .diff if result of sub is not zero

	inc rdi
	inc rsi
	jmp .loop

.done:
	ret

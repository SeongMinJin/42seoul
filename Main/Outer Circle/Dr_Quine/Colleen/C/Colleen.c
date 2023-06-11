#include <stdio.h>

/*
	This program will print its own source when run.
*/
void ft_printf() {
	char *s = "#include <stdio.h>%c%c/*%c%cThis program will print its own source when run.%c*/%cvoid ft_printf() {%c%cchar *s = %c%s%c;%c%cprintf(s, 10, 10, 10, 9, 10, 10, 10, 9, 34, s, 34, 10, 9, 10, 10, 10, 10, 9, 10, 9, 9, 10, 9, 10, 9, 10, 9, 10);%c}%c%cint main() {%c%c/*%c%c%cThis program will print its own source when run.%c%c*/%c%cft_printf();%c%creturn 0;%c}";
	printf(s, 10, 10, 10, 9, 10, 10, 10, 9, 34, s, 34, 10, 9, 10, 10, 10, 10, 9, 10, 9, 9, 10, 9, 10, 9, 10, 9, 10);
}

int main() {
	/*
		This program will print its own source when run.
	*/
	ft_printf();
	return 0;
}
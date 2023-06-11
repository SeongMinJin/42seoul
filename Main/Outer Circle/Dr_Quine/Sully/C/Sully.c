#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;
#define S "#include <stdio.h>%c#include <unistd.h>%c#include <fcntl.h>%c#include <stdlib.h>%c#include <string.h>%c%cextern char **environ;%c#define S %c%s%c%cint main() {%c%cint i = %d;%c%cif (!i) {%c%c%creturn 0;%c%c}%c%cchar source[30], execute[30], compile[100];%c%cbzero(source, 30);%c%cbzero(execute, 30);%c%cbzero(compile, 100);%c%csprintf(source, %cSully_%cd.c%c, i);%c%csprintf(execute, %cSully_%cd%c, i);%c%cint fd = open(source, O_RDWR | O_CREAT | O_TRUNC);%c%cdup2(fd, 1);%c%cclose(fd);%c%c--i;%c%cprintf(S, 10, 10, 10, 10, 10, 10, 10, 34, S, 34, 10, 10, 9, i, 10, 9, 10, 9, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 34, 37, 34, 10, 9, 34, 37, 34, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 34, 37, 37, 34, 10, 9, 10, 9, 10, 9, 10);%c%csprintf(compile, %ccc -Wall -Wextra -Werror %cs -o %cs%c, source, execute);%c%csystem(compile);%c%csystem(execute);%c%creturn 0;%c}"
int main() {
	int i = 5;
	if (!i) {
		return 0;
	}
	char source[30], execute[30], compile[100];
	bzero(source, 30);
	bzero(execute, 30);
	bzero(compile, 100);
	sprintf(source, "Sully_%d.c", i);
	sprintf(execute, "Sully_%d", i);
	int fd = open(source, O_RDWR | O_CREAT | O_TRUNC);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	--i;
	// printf(S, 10, 10, 10, 10, 10, 10, 10, 34, S, 34, 10, 10, 9, i, 10, 9, 10, 9, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 34, 37, 34, 10, 9, 34, 37, 34, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 34, 37, 37, 34, 10, 9, 10, 9, 10, 9, 10);
	// sprintf(compile, "cc -Wall -Wextra -Werror %s -o %s", source, execute);
	// system(compile);
	// system(execute);
	return 0;
}
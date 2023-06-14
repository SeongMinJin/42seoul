#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define S "#include <stdio.h>%c#include <stdlib.h>%c#include <string.h>%c#define S %c%s%c%cint main()%c{%c%cint i = %d;%c%cif (i < 1)%c%c%creturn 0;%c%cif (strcmp(__FILE__, %cSully.c%c))%c%c%c--i;%c%cchar source[20], execute[20], compile[100], cmd[20];%c%cbzero(source, 20);%c%cbzero(execute, 20);%c%cbzero(compile, 100);%c%cbzero(cmd, 20);%c%csprintf(source, %cSully_%cd.c%c, i);%c%csprintf(execute, %cSully_%cd%c, i);%c%csprintf(compile, %ccc -Wall -Werror -Wextra %cs -o %cs%c, source, execute);%c%csprintf(cmd, %c./%cs%c, execute);%c%cFILE *file = fopen(source, %cw%c);%c%cif (!file)%c%c%creturn 0;%c%cfprintf(file, S, 10, 10, 10, 34, S, 34, 10, 10, 10, 9, i, 10, 9, 10, 9, 9, 10, 9, 34, 34, 10, 9, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 34, 37, 34, 10, 9, 34, 37, 34, 10, 9, 34, 37, 37, 34, 10, 9, 34, 37, 34, 10, 9, 34, 34, 10, 9, 10, 9, 9, 10, 9, 10, 9, 10, 9, 10 ,9 ,10, 9, 9, 10, 9, 10);%c%cfclose(file);%c%csystem(compile);%c%cif (i > 0)%c%c%csystem(cmd);%c%creturn 0;%c}"
int main()
{
	int i = 5;
	if (i < 1)
		return 0;
	if (strcmp(__FILE__, "Sully.c"))
		--i;
	char source[20], execute[20], compile[100], cmd[20];
	bzero(source, 20);
	bzero(execute, 20);
	bzero(compile, 100);
	bzero(cmd, 20);
	sprintf(source, "Sully_%d.c", i);
	sprintf(execute, "Sully_%d", i);
	sprintf(compile, "cc -Wall -Werror -Wextra %s -o %s", source, execute);
	sprintf(cmd, "./%s", execute);
	FILE *file = fopen(source, "w");
	if (!file)
		return 0;
	fprintf(file, S, 10, 10, 10, 34, S, 34, 10, 10, 10, 9, i, 10, 9, 10, 9, 9, 10, 9, 34, 34, 10, 9, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 34, 37, 34, 10, 9, 34, 37, 34, 10, 9, 34, 37, 37, 34, 10, 9, 34, 37, 34, 10, 9, 34, 34, 10, 9, 10, 9, 9, 10, 9, 10, 9, 10, 9, 10 ,9 ,10, 9, 9, 10, 9, 10);
	fclose(file);
	system(compile);
	if (i > 0)
		system(cmd);
	return 0;
}
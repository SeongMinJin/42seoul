#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
/*
	This program will print its own source when run.
*/
#define S "#include <stdio.h>%c#include <unistd.h>%c#include <fcntl.h>%c/*%c%cThis program will print its own source when run.%c*/%c#define S %c%s%c%c#define FT()int main(){ FILE* file = fopen(%cGrace_kid.c%c, %cw%c); fprintf(file, S, 10, 10, 10, 10, 9, 10, 10, 34, S, 34, 10, 34, 34, 34, 34, 10); fclose(file); return 0; }%cFT();"
#define FT()int main(){ FILE* file = fopen("Grace_kid.c", "w"); fprintf(file, S, 10, 10, 10, 10, 9, 10, 10, 34, S, 34, 10, 34, 34, 34, 34, 10); fclose(file); return 0; }
FT();
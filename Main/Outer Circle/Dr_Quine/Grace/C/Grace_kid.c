#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
/*
	This program will print its own source when run.
*/
#define S "#include <stdio.h>%c#include <unistd.h>%c#include <fcntl.h>%c/*%c%cThis program will print its own source when run.%c*/%c#define S %c%s%c%c#define FD open(%cGrace_kid.c%c, O_WRONLY | O_CREAT)%c#define FT()int main(){ dup2(FD, STDOUT_FILENO); close(FD); printf(S, 10, 10, 10, 10, 9, 10, 10, 34, S, 34, 10, 34, 34, 10, 10); return 0; }%cFT();"
#define FD open("Grace_kid.c", O_WRONLY | O_CREAT)
#define FT()int main(){ dup2(FD, STDOUT_FILENO); close(FD); printf(S, 10, 10, 10, 10, 9, 10, 10, 34, S, 34, 10, 34, 34, 10, 10); return 0; }
FT();
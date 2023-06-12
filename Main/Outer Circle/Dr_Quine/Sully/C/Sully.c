#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#define CODE "#include <stdio.h>%c#include <unistd.h>%c#include <fcntl.h>%c#include <stdlib.h>%c#include <string.h>%c#define CODE %c%s%c%c#define SOURCE %cSully_%d.c%c%c#define EXECUTE %cSully_%d%c%c#define I %d%c#define FT()int main(){ FILE* file = fopen(SOURCE, %cw%c); fprintf(file, CODE, 10, 10, 10, 10, 10, 34, CODE, 34, 10, 34, I - 1, 34, 10, 34, I - 1, 34 , 10, I - 1, 10, 34, 34, 34, 37, 37, 34, 34, 37, 34, 10); fclose(file); if(!I) return 0; char compile[50]; bzero(compile, 50); sprintf(compile, %ccc -Wall -Werror -Wextra %cs -o %cs%c, SOURCE, EXECUTE); system(compile); char cmd[50]; bzero(cmd, 50); sprintf(cmd, %c./%cs%c, EXECUTE); system(cmd); return 0; }%cFT();"
#define SOURCE "Sully_5.c"
#define EXECUTE "Sully_5"
#define I 5
#define FT()int main(){ FILE* file = fopen(SOURCE, "w"); fprintf(file, CODE, 10, 10, 10, 10, 10, 34, CODE, 34, 10, 34, I - 1, 34, 10, 34, I - 1, 34 , 10, I - 1, 10, 34, 34, 34, 37, 37, 34, 34, 37, 34, 10); fclose(file); if(!I) return 0; char compile[50]; bzero(compile, 50); sprintf(compile, "cc -Wall -Werror -Wextra %s -o %s", SOURCE, EXECUTE); system(compile); char cmd[50]; bzero(cmd, 50); sprintf(cmd, "./%s", EXECUTE); system(cmd); return 0; }
FT();
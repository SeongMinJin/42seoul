#include "./libasm.h"
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/errno.h>

int main() {
	printf("----------TEST FOR `ft_strlen`----------\n");

	size_t myRes, oriRes;

	char *s1 = "Hello World!";
	char *s2 = "This is normal string.";
	char s3[20] = {244, 210, 97, 32, 10, 1, 2, 3, 4, 0, 'F'};
	char s4[10];
	char *s5 = "😀❤️😀❤️😀❤️😀❤️😀❤️😀❤️😀❤️😀❤️😀❤️😀❤️";
	char *s6 = "";
	char s7[1] = {0};

	myRes = ft_strlen(s1);
	oriRes = strlen(s1);
	printf("My :%zu Ori:%zu\n", myRes, oriRes);
	myRes = ft_strlen(s2);
	oriRes = strlen(s2);
	printf("My :%zu Ori:%zu\n", myRes, oriRes);
	myRes = ft_strlen(s3);
	oriRes = strlen(s3);
	printf("My :%zu Ori:%zu\n", myRes, oriRes);
	myRes = ft_strlen(s4);
	oriRes = strlen(s4);
	printf("My :%zu Ori:%zu\n", myRes, oriRes);
	myRes = ft_strlen(s5);
	oriRes = strlen(s5);
	printf("My :%zu Ori:%zu\n", myRes, oriRes);
	myRes = ft_strlen(s6);
	oriRes = strlen(s6);
	printf("My :%zu Ori:%zu\n", myRes, oriRes);
	myRes = ft_strlen(s7);
	oriRes = strlen(s7);
	printf("My :%zu Ori:%zu\n", myRes, oriRes);


	printf("\n\n----------TEST FOR `ft_strcpy`----------\n");
	char *src1 = "This is normal src";
	char *dst = calloc(100, 1);


	printf("TEST 1 - Normal String\n");
	printf("src:%s\n", src1);

	dst = ft_strcpy(dst, src1);
	printf("My :%s\n", dst);

	bzero(dst, 100);
	dst = strcpy(dst, src1);
	printf("Ori:%s\n", dst);
	printf("\n");


	printf("TEST 2 - Unicode\n");
	
	char *src2 = "Unicode string 🇰🇵🚣🏾‍♂️🇵🇹";
	printf("src:%s\n", src1);

	bzero(dst, 100);
	dst = ft_strcpy(dst, src2);
	printf("My :%s\n", dst);

	bzero(dst, 100);
	dst = strcpy(dst, src2);
	printf("Ori:%s\n", dst);
	printf("\n");



	printf("TEST 3 - Extension ASCII String\n");

	char src3[200] = {212, 124, 4, 124, 9, 22 ,42 , 0, 119, 112};
	printf("src:%s\n", src3);


	bzero(dst, 100);
	dst = ft_strcpy(dst, src3);
	printf("My :%s\n", dst);

	bzero(dst, 100);
	dst = strcpy(dst, src3);
	printf("Ori:%s\n", dst);
	printf("\n");


	printf("TEST 4 - Empty String\n");

	char *src4 = "";
	printf("src:%s\n", src4);


	bzero(dst, 100);
	dst = ft_strcpy(dst, src4);
	printf("My :%s\n", dst);

	bzero(dst, 100);
	dst = strcpy(dst, src4);
	printf("Ori:%s\n", dst);
	printf("\n");



	printf("\n\n----------TEST FOR `ft_strcmp`----------\n");

	printf("TEST 1.\n");
	printf("s1:%s\ns2:%s\n", s1, s1);
	printf("My :%d\nOri:%d\n", ft_strcmp(s1, s1), strcmp(s1, s1));
	printf("\n");

	printf("TEST 2.\n");
	printf("s1:%s\ns2:%s\n", s1, s2);
	printf("My :%d\nOri:%d\n", ft_strcmp(s1, s2), strcmp(s1, s2));
	printf("\n");

	printf("TEST 3.\n");
	printf("s1:%s\ns2:%s\n", s1, s3);
	printf("My :%d\nOri:%d\n", ft_strcmp(s1, s3), strcmp(s1, s3));
	printf("\n");

	printf("TEST 4.\n");
	printf("s1:%s\ns2:%s\n", s1, s4);
	printf("My :%d\nOri:%d\n", ft_strcmp(s1, s4), strcmp(s1, s4));
	printf("\n");

	printf("TEST 5.\n");
	printf("s1:%s\ns2:%s\n", s3, s5);
	printf("My :%d\nOri:%d\n", ft_strcmp(s3, s5), strcmp(s3, s5));
	printf("\n");




	printf("\n\n----------TEST FOR `ft_write`----------\n");

	printf("TEST 1 - Normal Case\n");
	printf("My :%zd, errno:%d\n", ft_write(1, s1, strlen(s1)), errno);
	printf("Ori:%zd, errno:%d\n", write(1, s1, strlen(s1)), errno);
	printf("\n\n");



	printf("TEST 2 - Invalid Fd\n");
	printf("My :%zd, errno:%d\n", ft_write(1249, s1, strlen(s1)), errno);
	printf("Ori:%zd, errno:%d\n", write(1249, s1, strlen(s1)), errno);
	printf("\n\n");



	printf("TEST 3 - Invalid Buffer\n");
	printf("My :%zd, errno:%d\n", ft_write(1, NULL, strlen(s1)), errno);
	printf("Ori:%zd, errno:%d\n", write(1, NULL, strlen(s1)), errno);
	printf("\n\n");



	errno = 0;
	printf("\n\n----------TEST FOR `ft_read`----------\n");
	int fd = open("./main.c", O_RDONLY);
	char buf[200];
	bzero(buf, 200);

	printf("TEST 1 - Normal Case\n");
	printf("My :%zd, ", ft_read(fd, buf, 200));
	printf("errno:%d\n", errno);
	printf("Ori:%zd, ", read(fd, buf, 200));
	printf("errno:%d\n", errno);
	printf("\n\n");


	printf("TEST 2 - Invalid Fd\n");
	printf("My :%zd, errno:%d\n", ft_read(128947, buf, 200), errno);
	printf("Ori:%zd, errno:%d\n", read(128947, buf, 200), errno);
	printf("\n\n");


	fd = open("./main.c", O_RDONLY);
	printf("TEST 3 - Invalid Buffer\n");
	printf("My :%zd, errno:%d\n", ft_read(fd, NULL, 200), errno);
	printf("Ori:%zd, errno:%d\n", read(fd, NULL, 200), errno);
	printf("\n\n");



	printf("\n\n----------TEST FOR `ft_strdup`----------\n");
	printf("TEST 1.\n");
	char *d = ft_strdup(s1);
	printf("src:%s\n", s1);
	printf("My :%s\n", d);
	free(d);
	d = strdup(s1);
	printf("Ori:%s\n", d);
	free(d);
	printf("\n\n");

	printf("TEST 2.\n");
	d = ft_strdup(s2);
	printf("src:%s\n", s2);
	printf("My :%s\n", d);
	free(d);
	d = strdup(s2);
	printf("Ori:%s\n", d);
	free(d);
	printf("\n\n");


	printf("TEST 3.\n");
	d = ft_strdup(s3);
	printf("src:%s\n", s3);
	printf("My :%s\n", d);
	free(d);
	d = strdup(s3);
	printf("Ori:%s\n", d);
	free(d);
	printf("\n\n");

	printf("TEST 4.\n");
	d = ft_strdup(s4);
	printf("src:%s\n", s4);
	printf("My :%s\n", d);
	free(d);
	d = strdup(s4);
	printf("Ori:%s\n", d);
	free(d);
	printf("\n\n");


	printf("TEST 5.\n");
	d = ft_strdup(s5);
	printf("src:%s\n", s5);
	printf("My :%s\n", d);
	free(d);
	d = strdup(s5);
	printf("Ori:%s\n", d);
	free(d);
	printf("\n\n");



	system("leaks $PPID");
	return 0;
}
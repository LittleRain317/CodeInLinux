#include "../include/apue.h"

#define BSZ 48
void fun(char* str, int size)
{
	for (int i = 0; i != size; ++i)
		printf("%c", str[i]);
	printf("\n");
}
#define TEST do { printf("测试:"); fun(buf, BSZ);} while (0)
int main()
{
	FILE* fp;
	char buf[BSZ];

	memset(buf, 'a', BSZ - 2);
	buf[BSZ - 2] = '\0';
	buf[BSZ - 1] = 'X'; //buf aaaaaaaaaaaa0X
	TEST;	
	if ((fp = fmemopen(buf, BSZ, "w+")) == NULL) //buf 00000000000000
	{
		err_sys("fmemopen failed");
	}
	TEST;
	printf("initial buffer contents: %s\n", buf); // buf 000000000000
	TEST;
	fprintf(fp, "hello, world"); //io hello,world
	printf("before flush: %s\n", buf); // buf 0000000000000
	TEST;
	fflush(fp);//io 0
	TEST;
	printf("after fflush: %s\n", buf); // buf hello,world
	TEST;
	printf("len of string in buf = %ld\n", (long)strlen(buf));
	memset(buf, 'b', BSZ-2); 
	buf[BSZ-2] = '\0';
	buf[BSZ-1] = 'X';//buf bbbbbbbbbbbb0X
	TEST;
	fprintf(fp, "hello, world"); //hello, world
	TEST;
	fseek(fp, 0, SEEK_SET);  //写入0
	TEST;
	printf("after fseek: %s\n", buf); //0
	TEST;
	printf("len of string in buf = %ld\n", (long)strlen(buf)); //0

	memset(buf, 'c', BSZ - 2);
	buf[BSZ - 2] = '\0';
	buf[BSZ - 1] = 'X'; //ccccccccc0X
	TEST;
	fprintf(fp, "hello, world"); //io hello
	TEST;
	fclose(fp); //hello world0ccccccc0X
	TEST;
	printf("after fclose: %s\n", buf);
	TEST;
	printf("len of string in buf = %ld\n", (long)strlen(buf));
	return 0;
}

#include <stdio.h>
#include <setjmp.h>
#include <stdnoreturn.h>
 
jmp_buf jump_buffer;
 
void a(int count) 
{
    printf("a(%d) called\n", count);
    longjmp(jump_buffer, count+1); // 将从 setjmp 外 count+1
}
void te();
 
int main(void)
{
	printf("测试\n");
	int b = 20;
	printf("a = %d\n", b);
	te();
	printf("te\n");
	a(1);
}

void te()
{
	printf("%s\n", __FUNCTION__);
	if (setjmp(jump_buffer))
	{
		printf("成立\n");
	}
	else
	{
		printf("不成立\n");
	}
}

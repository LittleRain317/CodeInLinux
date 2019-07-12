#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int mygetline(char line[], int maxline);
void copy(char to[], char form[]);

main()
{
	int len; //当前长度
	int max; //最长长度
	char line[MAXLINE]; //当前输入行
	char longest[MAXLINE]; //最长输入行

	max = 0;
	while ((len = mygetline(line, MAXLINE)) > 0)
		if (len > max){
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		printf("%s", longest);

	system ("pause");
	return 0;
}

int mygetline(char s[], int lim)
{
	int c, i;

	for (i - 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

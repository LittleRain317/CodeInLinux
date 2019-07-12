#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* FA (char*, char*);
typedef FA* ( * (*FB) (char*) ) [2];

FA stradd;
FA* fa[2] = {stradd, stradd};

char *(*(* func (char* _24k))[2])(char*, char*)
{
	return &fa;
}

int main()
{
	FB fb = func;

	printf("%s\n", (*fb("")) [0] ("24", "k") );

	return 24-'k';
}

char* stradd(char *s1, char *s2)
{
	char *s = (char*) malloc (strlen(s1) + strlen(s2) + 1);
	*s = 0;
	strcat(s, s1);
	strcat(s, s2);
	return s;
}


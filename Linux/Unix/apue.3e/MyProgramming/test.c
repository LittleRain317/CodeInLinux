#include <stdio.h>
#include <unistd.h>
#include <termios.h>
int main()
{

	printf("pid=%d ppid=%d pgid=%d tc=%d sid=%d\n", getpid(), getppid(), getpgrp(), tcgetpgrp(STDIN_FILENO), tcgetsid(STDIN_FILENO));
	if (setsid() == -1)
	{
		perror(NULL);
		return -1;
	}
	printf("pid=%d ppid=%d pgid=%d tc=%d sid=%d\n", getpid(), getppid(), getpgrp(), tcgetpgrp(STDIN_FILENO), tcgetsid(STDIN_FILENO));
	perror(NULL);
	tcsetpgrp(STDIN_FILENO, getpgrp());
	perror(NULL);
	printf("tcgetpgrp=%d\n", tcgetpgrp(STDIN_FILENO));
	perror(NULL);
	return 0;
}

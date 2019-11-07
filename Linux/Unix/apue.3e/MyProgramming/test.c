#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <signal.h>
void sig_tin(int signo)
{
	printf("signo=%d\n", signo);
}
int main()
{
	printf("pid=%d ppid=%d pgid=%d tcgetsid=%d tcgetpgrp=%d  \
			\t stdout=%d stderr=%d\n", getpid(), getppid(), getpgrp(), tcgetsid(STDIN_FILENO), tcgetpgrp(STDIN_FILENO),
				tcgetpgrp(STDOUT_FILENO), tcgetpgrp(STDERR_FILENO));
	if (setsid() == -1)
	{
		perror(NULL);
		return -1;
	}
	printf("pid=%d ppid=%d pgid=%d sid=%d \n", getpid(), getppid(), getpgrp(), getsid(0));
	return 0;
}

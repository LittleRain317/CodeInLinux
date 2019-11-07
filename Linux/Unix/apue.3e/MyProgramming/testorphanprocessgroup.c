#include <apue/apue.h>
#include <errno.h>
#include <time.h>
static void sig_hup(int signo)
{
	printf("SIGHUP received, pid = %ld\n", (long)getpid());
}
static void sig_cont(int signo)
{
	printf("SIGCONT received, pid = %ld\n", (long)getpid());
}
static void pr_ids(char *name)
{
	printf("%s: pid = %ld, ppid = %ld, pgrp = %ld, tpgrp = %ld\n", 
			name, (long)getpid(), (long)getppid(), (long)getpgrp(),
			(long)tcgetpgrp(STDIN_FILENO));
	fflush(stdout);
}

int main(void)
{
	char c;
	pid_t pid;
	pid_t pid2;
	pr_ids("parent");
	if ((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if (pid > 0)
	{
		pid2 = fork();
		if (pid2 == 0)
		{
			printf("我是另外一个子进程\n");
			pr_ids("另外");
			signal(SIGHUP, sig_hup);
			signal(SIGCONT, sig_cont);
			//
			clock_t start = clock();
			clock_t end;
			while (((end - start) / CLOCKS_PER_SEC) <= 10)
			{
				end = clock();
			}
			pr_ids("另外");
		}
		sleep(5);
	}
	else 
	{
		pr_ids("child");
		signal(SIGHUP, sig_hup);
		signal(SIGCONT, sig_cont);
		//kill(getpid(), SIGTSTP);
		printf("已经停止\n");
		clock_t s = clock();
		clock_t e;
		while (((e - s) / CLOCKS_PER_SEC) <= 10)
		{
			e = clock();
		}
		pr_ids("child");
		/*if (read(STDIN_FILENO, &c, 1) != 1)
		{
			printf("read error %d on controlling TTY\n", errno);
			perror(NULL);
		}
		*/
	}
	exit(0);
}

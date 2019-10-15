#include <stdint.h>
#include <errno.h>
typedef uint32_t mysigset_t;

#define SIGBAD(signo) ((signo) <= 0 || (signo) >= 32)

#define sigemptyset(signo) (*(signo) = (uint32_t)0)
#define sigfillset(signo) ((*(signo) = (uint32_t)-1), 0)

int sigaddset(mysigset_t* set, int signo)
{
	if (SIGBAD(signo))
	{
		errno = EINVAL;
		return -1;
	}
	*set |= 1 << (signo - 1);
	return 0;
}

int sigdelset(mysigset_t* set, int signo)
{
	if (SIGBAD(signo))
	{
		errno = EINVAL;
		return -1;
	}
	*set &= ~(1 << (signo - 1));
	return 0;
}

int sigismember(const mysigset_t* set, int signo)
{
	if (SIGBAD(signo))
	{
		errno = EINVAL;
		return -1;
	}
	return *set & (1 << (signo - 1));
}

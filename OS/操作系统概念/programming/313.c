#include "313.h"

unsigned char bitMap[SIZE] = { 0 };

static bool check(int pid)
{
	if (pid < MIN_PID || pid > MAX_PID)
		return false;
	int byte = pid / 8;
	int rest = pid % 8;
	if (!rest)
	{
		return bitMap[byte - 1] & 0x80;
	}
	else
	{
		return (bitMap[byte] >> (rest - 1)) & 0x1;
	}
}

static bool set(int pid)
{
	if (pid < MIN_PID || pid > MAX_PID)
		return false;
	int byte = pid / 8;
	int rest = pid % 8;
	if (!rest)
	{
		bitMap[byte - 1] |= 0x80;
	}
	else
	{
		int num = 0x1;
		num <<= rest - 1;
		bitMap[byte] |= num;
	}
	return true;
}

static bool clean(int pid)
{
	if (pid < MIN_PID || pid > MAX_PID)
		return false;
	int byte = pid / 8;
	int rest = pid % 8;
	if (!rest)
	{
		int num = 0;
		num = bitMap[byte - 1] - 0x80;
		if (check(pid))
		{
			bitMap[byte - 1 ] = num;
		}
		return true;
	}
	else
	{
		int num = 0x1;
		num <<= rest - 1;
		if (check(pid))
			bitMap[byte] -= num;
		return true;
	}
	return true;
}

int allocate_map(void)
{
	return 1;
}
int allocate_pid(void)
{
	int pid = 0;
	return pid;
	return -1;
}

void release_pid(int pid)
{
}



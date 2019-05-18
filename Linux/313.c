#include <stdio.h>
#define MIN_PID 300
#define MAX_PID 5000
unsigned char pidList[625];
int allocate_map(void);//创建并初始化一个用于表示pid的数据结构,如果不成功返回-1，如果成功，则返回1
int allocate_pid(void);//分配并返回一个pid，如果无法分配一个pid则返回-1
void release_pid(int pid);//释放一个pid
int main(void)
{
}


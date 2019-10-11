#include <stdbool.h>
#define MIN_PID 300
#define MAX_PID 5000
#define BYTESIZE ((MAX_PID - MIN_PID + 1) / 8)
#define MOD ((MAX_PID - MIN_PID + 1) % 8)
#define SIZE  ((MOD ? (BYTESIZE + 1) : (BYTESIZE)))

unsigned char bitMap[SIZE];
int allocate_map(void);//创建并初始化一个用于表示pid的结构，成功返回1失败-1
int allocate_pid(void);//返回一个可用pid，否则-1
void release_pid(int pid);//释放一个pid



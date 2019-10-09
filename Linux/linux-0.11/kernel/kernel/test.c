#include <stdio.h>

struct task_struct
{
	long utime; //用户时间
	long stime; //系统时间
};

struct timer
{
	long jiffies; //系统启动后的CPU滴答数
	void (*fn)(void);//时间片结束后该执行的函数
	struct timer * next;//定时器链表
};

struct timer * next_timer;
struct task_struct *current;

int main()
{
}

void do_timer(int cpl) //每进行一次IRQ0则调用该函数处理时间中断
{
//	extern int beepcount;
//	extern void sysbeepstop(void);

//	if (beepcount) //beepcount为蜂鸣器的鸣叫时间 
		//蜂鸣器 广泛应用于计算机、打印机、复印机、报警器、电子玩具、汽车电子设备、电话机、定时器等电子产品中作发声器件。
//		if (!--beepcount)
//			sysbeepstop();

	if (cpl)
		current->utime++; //user time
	else
		current->stime++; //system time cpl(当前特权级 0 为内核态)

	if (next_timer) { //定时器链表
		next_timer->jiffies--; //jiffies用于记录自系统启动以来所经过的时钟滴答数
		while (next_timer && next_timer->jiffies <= 0) {
			void (*fn)(void);
			
			fn = next_timer->fn;
			next_timer->fn = NULL;
			next_timer = next_timer->next;
			(fn)(); //调用该定时器的处理函数
		}
	}
	if (current_DOR & 0xf0) //0xf0 11110000 16
		do_floppy_timer();
	if ((--current->counter)>0) return;
	current->counter=0; //当前进程在本次的CPU时间片使用完
	if (!cpl) return;  //内核态进程直接退出
	schedule();  //用户态进程开始进程调度
}

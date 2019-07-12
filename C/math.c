#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
bool isShoot(int * bulletNum);
//int bulletNum = 6;
typedef struct targetArr
{
	long long int beShootNum;
	double p;
}targetArr;
bool isPrint(targetArr * arr)
{
	for (int i = 0; i < 5; ++i)
		if (arr[i].beShootNum == 0)
			return true;
	return false;
}
int main(void)
{
	srand((unsigned)time(NULL));
	int bulletNum = 6;
	int count = 0;
//	long long int targetArr[5] = {0};
	targetArr arr[5];
	for (int index = 0; index < 5; ++index)
	{
		arr[index].beShootNum = 0LL;
		arr[index].p = 0.0;
	}
	while (true){

		while (bulletNum != 0)
		{
			for (int index = 0; index < 5; ++index)
			{
				if (isShoot(&bulletNum))
				{
					bulletNum--;
			//	printf("子弹残余情况:%d\n", bulletNum);
					arr[index].beShootNum++;
			//	bulletNum--;
			//	arr[index].p *= (bulletNum + 1)/ 6.0;
				}
			//printf("%d号子弹当前概率:%f\n", index + 1, arr[index].p);
				else
				{
					if (arr[index].p == 0.0)
						arr[index].p = 1 - bulletNum / 6.0;
					arr[index].p *= 1 - bulletNum / 6.0;
				}
			}	
			++count;
		//	if (isPrint(arr))
		//	{
				printf("%d轮的结果如下:\n", count);
//				for (int index = 0; index < 5; ++index)
//				{
					printf("%d号中弹情况:%lld %f\n",1, arr[1].beShootNum, arr[1].p);
//				}
		//	}
			printf("\n");
		}
	//	sleep(3);
	//	printf("返回");
		bulletNum = 6;
		count = 0;
		memset(arr, 0, sizeof(arr));
	}
	return 0;
}

bool isShoot(int * bulletNum)
{
	if (rand() % 6 + 1 <= (*bulletNum))
	{
	//	(*bulletNum)--;
		return true;
	}
	else
	{
		return false;
	}
}

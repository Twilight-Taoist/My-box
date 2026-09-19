#include <stdio.h>

int main()
{
	int t1=0,t2=0,t=0;
	printf("初始时间：");
	scanf("%d",&t1);
	
	int hour1=t1/100,min1=t1%100;
	printf("经过时间：");
	scanf("%d",&t2);
    t=(hour1*60+min1)+t2;
    int hour2=t/60,min2=t%60;
    printf("当前时间为%d时%d分。",hour2,min2);
    
    return 0;
}

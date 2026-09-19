#include <stdio.h>

int main()
{
	int a=0;
	printf("请输入一个三位数：");
	scanf("%d",&a);
	int b,c,d,e,f;
	b=a/100;
	c=a%100;
	d=c/10;
	e=c%10;
	
	f=e*100+d*10+b; 
	printf("%d",f);
	
	return 0;
}

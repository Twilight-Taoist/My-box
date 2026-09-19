#include <stdio.h>

int main()
{
	int a=0;
	scanf("%d",&a);
	int b,c,d;
	b=a/16;
	c=a%16;
	int x=(b*10+c);
	printf("%x",x);
	return 0;
}

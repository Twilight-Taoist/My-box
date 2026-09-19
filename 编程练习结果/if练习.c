#include <stdio.h>

int main()
{
	int a=0,b=0,c=0;
	printf("请输入三个需要比较大小的数字：");
	scanf("%d %d %d",&a,&b,&c);
	
	if (a>b){if (a>c) printf("max=%d",a);
	else printf("max=%d",c);
	}
	else if (b>c) printf("max=%d",b);
	else printf("max=%d",c);
	
	return 0;
}

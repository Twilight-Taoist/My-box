#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));
	int a=rand()%100+1;
	int b=0;
	int c=0;

	
	printf ("我已经想好了一个100以内的数");
	do {
		printf ("来猜：");
		scanf ("%d",&b);
		c++;
		if ( b>a ){
			printf("你猜大了。\n");
		}else if ( b<a ){
			printf("你猜小了。\n");
		}
	}while ( b!=a );
	
	printf ("恭喜你，猜对了，你一共猜了%d次。",c);
	
	return 0;
}

#include <stdio.h>
int main()
{
	int a;
	int b;
	int c;
	scanf ("%d/%d",&a,&b);
	int i=a,j=b;
	c=a%b;
//	printf ("%d %d",a,b);
	while (c!=0){
		c=a%b;
		a=b;
		if(c!=0){b=c;
		}
	}
	printf("%d/%d\n",i/b,j/b);	
		
	return 0;
}

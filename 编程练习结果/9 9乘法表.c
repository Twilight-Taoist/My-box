#include <stdio.h>
int main()
{
	int n;
	scanf ("%d",&n);
	int a=1,b=1;
	while (a<=n){
		b=1;
		while ( b<=a){
			int c=a*b;
			printf ("%d*%d=%d",b,a,c);
			b++;
			if (c<=9){
				printf("   ");
			}else{
				printf ("  ");
			}
		}
		printf("\n");
		a++;
		
	}
	
	
	
	return 0;
}

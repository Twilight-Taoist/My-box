#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int first=1;
	int i=1;
	while (i<n){
		first *= 10;
		i++;
	}
    i=first;
//	printf ("%d",first);
    while(i<first*10){
    	int t=i;
    	int sum=0;
    	do{
		   int a=t%10;
    	   t/=10;
    	   int b=1;
    	   int c=0;
    	   while (c<n){
    		b *= a;
    		c++;
		   }
		   sum += b;
	    }while (t>0);
	    if (sum==i){
	    	printf ("%d\n",i);
		}
    	i++;
	}

	return 0;
}

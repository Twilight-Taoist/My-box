#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	double i=1.0;
	double t=2.0;
	double k=0.0; 
	int cnt=0;
	double sum=0.0;
	
	while (cnt<n){
		sum+=t/i;
		k=t;
    	t+=i;
    	i=k;
		cnt++;
	}
	printf ("%.2f",sum);
	
	return 0;
}


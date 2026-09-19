#include<stdio.h>
int main()
{
	int a;
	int x=0;
	int n;
	scanf("%d %d",&a,&n);
	int cnt=0;
	int sum;
	
	do{
	   x=x*10+a;
	   sum+=x;
	   cnt++;		
	}while(cnt!=n);
	printf("%d",sum);
		
	return 0;
}

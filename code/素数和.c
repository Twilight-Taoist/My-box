#include <stdio.h>
int main()
{
	int N;
	int M;
	scanf ( "%d %d",&M,&N);
	int cnt=0;
	int sum=0;
	
	for ( ;M<=N;M++){
		int t=M;
		while (t>0){
		   int i=0;
		   int a=0;
		   while(t>0){
		   	a=M%t;
		   	if(a==0){
		   		i++;
		   		t--;
			   }else{t--;
			   }
			   //printf ("%d",t);
		   }
		   if (i==2){
		   	sum += M;
		   	cnt++;
		   }
		}
	}
	printf ("%d %d",cnt,sum);

	
	return 0;
}

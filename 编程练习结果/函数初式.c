#include <stdio.h>

int sum(int a,int b);

int main(){
	int a;
	int b;
	int max;
	scanf("%d %d",&a,&b);
	max=sum(a,b);
	printf ("max=%d",max);
}

int sum(int a,int b){
	int ret;
	if(a<b){
		ret=b;
	}else if(a>b){
		ret=a;
	}
	return ret;
}

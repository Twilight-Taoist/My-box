#include <stdio.h>

int main()
{
	int f=0; 
	scanf("%d",&f);
	
	if (f<0) {
	  f=-1;
	}else if (f==0){
	  f=0;
	}else {
	  f=2*f; 
	}
	
	printf("%d",f);
	
	return 0;
}

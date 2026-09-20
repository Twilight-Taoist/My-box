#include <stdio.h>

int main()
{
	int x;
	int i;
	int key=1;
	
	scanf ("%d",&x);
	for ( i=2 ; i<x ; i++ ){
		if ( x%i==0 ){
			key = 0;
			break;
		}
		
	}
	if ( key == 1){
		printf ("是素数");
	}else {
		printf ("不是素数");
	}
	
	return 0;
}

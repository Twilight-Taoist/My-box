#include <stdio.h>

int main()
{
	int a[5]={0};
	int b[5]={0,0,0,0,0};
	int c[5];
	int i;
	
	for ( i=0 ;i<sizeof(c)/sizeof(c[0]) ; i++){
		c[i]=0;
	}
	for ( i=0 ;i<sizeof(c)/sizeof(c[0]) ; i++){
		printf ("%d %d %d\n",a[i],b[i],c[i]);
	}
	
	
	return 0;
}

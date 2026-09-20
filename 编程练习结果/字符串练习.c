#include <stdio.h>
int main()
{
	char month[12][12]={
	"January","February","san","May",
	}; 
	int i;
	scanf ("%d",&i);
	printf ("%s ",month[i-1]);
	
	return 0;
}

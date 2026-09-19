#include <stdio.h>

int main()
{
	int fact = 1;
	int n = 1;
	int i=1;
	
	scanf ("%d",&n);
	i=n;
	for ( n=n ; n > 1; n--){
		fact *= n;
	}
	printf ("%d\n%d",i,fact);
	
	return 0;
}

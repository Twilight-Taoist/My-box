#include <stdio.h>
#include <string.h>

int my_strlen(char *a){
	int cnt=0;
	while ( *a != '\0'){
		cnt++;
		a++;
	}
	return cnt;
}

int main()

{
	int cnt;
    char a[10]="hello";
	cnt=my_strlen(a);
	printf ("%d %d ",cnt,strlen(a));
	
	return 0;
}

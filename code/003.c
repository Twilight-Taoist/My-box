#include <stdio.h>

void set_zero(int **pp){
	**pp=0;
	printf("%d ",**pp);
}               /* 把 *pp 指向的那个 int 置 0 */
void point_to(int **pp, int *target){
	*pp=target;
}  /* 让调用者的指针改指向 target */

int main()
{
	int i=6;
	int *p=&i;
	int **pp=&p;
	set_zero(pp);
	printf ("%d\n",i);
	int j=9;
	int *target=&j;
	point_to(pp,target);
	printf("j=%d %d",*p,p==&j);
	
	return 0;
}



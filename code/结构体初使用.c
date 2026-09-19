#include <stdio.h>
#include <string.h>

struct student{
	int number; 
	char name[20];
	double point;
};

 struct student* into(int n){
	struct student p[n];
	int i;
	int *sp0;
	for ( i=0 ; i<n ; i++){
		scanf ("%i %s %i",p[i].number,p[i].name,p[i].point);
	}
	sp0=&p;
	
	return sp0;
	
}

int main (void)
{
	int n;
	scanf("%d",&n);
	int *sp1;
	int i;
	int sum;
	
	*sp1=struct student* into(n);
	
	for(i=0;i<n;i++){
		sum+=*sp1->point[i];
	} 
	printf ("%.2f",sum/n);
	
	return 0;
}

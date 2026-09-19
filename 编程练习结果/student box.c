#include <stdio.h>
#include <string.h>

struct Student{
	int number;
	char name[20];
	double score;
};


int main ()
{
	int n;
	scanf ("%d",&n);
	struct Student s1[n];
	int i;
	
	for (i=0;i<n;i++){
	scanf ("%d %s %lf",&s1[i].number,s1[i].name,&s1[i].score);
//    printf ("%d %s %f",s1[i].number,s1[i].name,s1[i].score);
	}
	
	double sum=0.0;
	for (i=0;i<n;i++){
		sum+=s1[i].score;
	}
	printf ("%.2f",sum/i);
	
	return 0;
}

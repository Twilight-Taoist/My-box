#include <stdio.h>
#include <string.h>

struct Student{
	char name[20];
	int score;
};

int main ()
{
	struct Student arr[3] = {{"Tom", 90}, {"Jerry", 85}, {"Spike", 70}};
	struct Student *pa; 
	pa=arr;
	int i;
	for (i=0;i<3;i++){
	printf ("%s %d\n",pa->name,pa->score);
	pa++;
    }
	return 0;
}

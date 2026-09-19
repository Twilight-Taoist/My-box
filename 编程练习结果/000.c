#include <stdio.h>
#include <string.h>

struct Student {
	char name[10];
	int score;
};

int main ()
{
	struct Student s1;
	struct Student *ps;
	ps=&s1;
	strcpy (s1.name,"Tom");
	printf ("%s",ps->name);
	
	return 0;
}

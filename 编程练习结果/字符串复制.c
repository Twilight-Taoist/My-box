#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *dup_string(const char *s){
	size_t n;
	char *copy;
	
	if (s==NULL){
		return NULL;
	}
	
	n=strlen(s)+1;
	copy=malloc(n);
	if (copy==NULL){
		return NULL; 
	}
	memcpy(copy,s,n);
	return copy;
}

int main ()
{
	return 0;
}

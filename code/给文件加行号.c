#include <stdio.h>
#define SAMPLE "example.txt"

static void make_sample(const char *path){
	FILE *fp=fopen(path,"w");
	if ( fp == NULL ) return ;
	fputs("one\ntwo\n\nthree\n",fp);
	fclose(fp);
}

static int print_numbered(const char *path,int skip_blank,long *printed){
	
	FILE *fp=fopen(path,"r");
	if( fp ==NULL) return -1;
	
	char buf[128];
	long n=0;
	while(fgets(buf,sizeof (buf),fp)!=NULL){
		if (skip_blank && buf[0]=='\n') continue;
		n++;
		printf ("%ld=%s",n,buf);
	}
	*printed=n;
	fclose(fp);
	return 0;
} 


int main()
{
	long printed;
	int rc;
	
	make_sample(SAMPLE);
	rc=print_numbered(SAMPLE,0,&printed);
	printf("print_return= %d\n",rc);
	printf("print_all=%ld\n",printed);
	
	rc=print_numbered(SAMPLE,1,&printed);
	printf("print_return= %d\n",rc);
	printf("print_skip=%ld\n",printed);
	remove(SAMPLE);
	
	return 0;
}

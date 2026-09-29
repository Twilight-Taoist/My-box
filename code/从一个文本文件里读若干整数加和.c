#include <stdio.h>
#define SAMPLE1 "sample_1.txt"
#define SAMPLE2 "sample_2.txt"

int sum_ints(const char *path, long *sum, long *count){
	
	long s=0;
	long c=0;
	long i=0;
	
	FILE *fp=fopen(path,"r");
	if (fp ==NULL) {
		*sum=s;
		*count=c;
		return -1;
	}
	while (fscanf(fp,"%d",&i)==1){
		s+=i;
		c++;
	}
	*sum=s;
	*count=c;
	fclose(fp);
	return 0;
	
}

int main()
{
	long sum,count;
	int rc;
	
	FILE *fp1=fopen(SAMPLE1,"w");
	if (fp1==NULL) return -1;
	fputs("3 4 5\n",fp1);
	fclose(fp1);
	
	rc=sum_ints(SAMPLE1,&sum,&count);
	printf("rc=%d\nsum=%ld\ncount=%ld\n\n",rc,sum,count);
	
	FILE *fp2=fopen(SAMPLE2,"w");
	if ( fp2 == NULL ) return -1;
	fputs("7 abc 9\n",fp2);
	fclose (fp2);
	rc=sum_ints(SAMPLE2,&sum,&count);
	printf("rc=%d\nsum=%ld\ncount=%ld\n\n",rc,sum,count);
	
	return 0;
}

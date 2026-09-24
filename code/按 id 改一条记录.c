#include<stdio.h>
#define SAMPLE "example_13_4.txt"

struct rec{
	double value;
	int id;
	char tag;
};

 int make_sample_v1(const char *path ,int n){
	
	FILE *fp=fopen(path,"wb");
	if (fp==NULL) return 1;
	
	struct rec r;
	int k=0;
	
	for(k=0;k<n;k++){
		r.id=100+k;
		r.value=k*1.5;
		r.tag=(char)('A'+k);
		fwrite(&r,sizeof (r),1,fp);
	}
	fclose(fp);
	return 0;
}

static int update_by_id(const char *path, int id, double new_value){
	
	FILE *fp=fopen(path,"r+b");
	if (fp == NULL) return -1;
	struct rec back;
	struct rec i;
	long n=0;
	while (fread(&back,sizeof(back),1,fp)==1){
		fseek(fp,n*sizeof(back),SEEK_SET);
		if (back.id==id){
			back.value=new_value;
			fwrite(&back,sizeof(back),1,fp);
			break;
	    }
	    n++;
		fseek(fp,n*sizeof(back),SEEK_SET);
	}
	if(fread(&i,sizeof(i),1,fp)!=1) return 1;
	
	fclose(fp);
	
	return 0;
}

static void printf_all(const char *path){
	
	FILE *fp=fopen(path,"rb");
	if (fp==NULL) return;
	struct rec print;
	while(fread(&print,sizeof(print),1,fp)==1){
		printf("value: %.2lf\nid: %d\n",print.value,print.id);
	}
	fclose(fp);
}



int main ()
{
	int rc1=0,rc2=0;
	int n;
	
	scanf("%d",&n);
	rc1=make_sample_v1(SAMPLE,n);
//	printf_all(SAMPLE);
	if (rc1){
		printf ("can_not_opean_make");
		return 1;
	}
	
	rc2=update_by_id(SAMPLE,102,4.18);
	printf ("update:%d\n",rc2);
	printf_all(SAMPLE);
	
	rc2=update_by_id(SAMPLE,999,9);
	printf ("update:%d\n",rc2);
	printf_all(SAMPLE);
	
	remove(SAMPLE);
	return 0;
}

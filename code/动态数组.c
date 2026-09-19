#include <stdio.h>
#include <stdlib.h>

typedef struct  {
	int *array;
	int size;
} Array; 

Array array_create (int inte_size){
	Array a;
	a.size=inte_size;
	a.array=(int*)malloc(inte_size*sizeof(int));
	
	return a;
}
void array_free(Array *a){
	free (a->array);
	a->array=NULL;
	a->size=0;
}

int array_size(Array *a){
	return a->size;
}

int* array_at(Array *a,int index){
	const int NUMBER=20;
	if (index>=array_size(a)){
	array_moresize(&a,((index-a->size)/NUMBER)+1,array_size(a),NUMBER);
    }else { 
//    printf ("1=%d",array_size(a));
    return &(a->array[index]);
	}
    
}

void array_moresize(Array *a,int moresize,int size,const int NUMBER){
	printf ("%d\n",(moresize*NUMBER+size));
	int *p=(int*)malloc((moresize*NUMBER+size)*sizeof(int));
	int i;
	for (i=0;i<size;i++){
		p[i]=a->array[i];
	}
	free(a->array);
	a->array=p;
	a->size=moresize*NUMBER+size;
	return &a;
}

int main ()
{
	int inte_size;
	Array a;
	int index;
	scanf ("%d",&inte_size);
	a=array_create(inte_size);
	index=12;
	*array_at(&a,index)=10;
	
//	printf ("%d ",sizeof(a.array));
	printf ("%d\n",array_size(&a));
	printf ("%d\n",*array_at(&a,index));

	array_free (&a);
	return 0;
}

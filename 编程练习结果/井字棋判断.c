#include <stdio.h>

//int check(int i,int j,int size,int number[size][size]){
//	int x,o;
//	int result=-1;
		
//	return result;    
//}



int main()
{
	int size=3;
	int number[size][size];
	int i;
	int j;
	int x;
	int o;
	int result=-1;
	
	for ( i=0 ; i<size ; i++){
		for ( j=0 ; j<size ; j++){
			scanf ("%d",&number[i][j]);
			}
	}
/*	{
		for ( i=0 ;i<size; i++){
			for (j=0; j<size ; j++){
				printf ("%d ",number[i][j]);
			}
		}
	}
	
    result=check(i,j,size,number);
    printf("%d",result);
    result=check(j,i,size,number);
    printf("%d",result); */
    for ( i=0; i<size && result==-1 ; i++){
			x=o=0;
			for ( j=0 ; j<size ; j++){
				if ( number[i][j]==1 ){
					x++;
				}else {
					o++;
				}
				
			}
			if ( x==size ){
				result=1;
			}else if ( o==size ){
				result=0;
			}else {
				result=-1;
			}
	    }
	    
	    for ( i=0; i<size && result==-1 ; i++){
			x=o=0;
			for ( j=0 ; j<size ; j++){
				if ( number[j][i]==1 ){
					x++;
				}else {
					o++;
				}
				
			}
			if ( x==size ){
				result=1;
			}else if ( o==size ){
				result=0;
			}else {
				result=-1;
			}
	    }
	    printf ("%d",result);
	
   return 0;	
}

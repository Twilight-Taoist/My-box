#include <stdio.h>

int main()
{   int x = 2;
	int cunt=0;
    
     while ( cunt <25 ){
    	int i;
    	int key=1;
    	for ( i=2; i<x; i++){
    		if ( x%i==0 ){
    			key=0;
    			break;
			}
	    }
		if ( key==1 ){
			printf(" %d",x);
			cunt++;
		}
		x++;		
	}
	printf("\n");
	
    return 0;
}

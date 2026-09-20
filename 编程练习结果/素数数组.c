#include <stdio.h>

int main()
{
	int maxNUMBER;
	scanf ( "%d",&maxNUMBER);
	int isPrime[maxNUMBER];
	int i;
	int x;
	
	for ( i=0 ; i<maxNUMBER ; i++ ){
		isPrime[i]=1;
	}
	
	for ( x=2 ; x<maxNUMBER ; x++){
		if( isPrime[x] ){
			for ( i=2 ; x*i<maxNUMBER ; i++){
				isPrime[ i*x ]=0;
			}
		}
		
	}
	
	for ( i=2 ; i<maxNUMBER ; i++){
		if( isPrime[i] ){
			printf ("%d\t",i);
		}
	}
	
	printf ("\n");
	
	return 0;
}

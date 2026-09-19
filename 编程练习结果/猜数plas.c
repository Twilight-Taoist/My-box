#include <stdio.h>
int main()
{
	int random;
	int max;
	int cnt=0;
	int i;
	scanf ("%d %d",&random,&max);
	do{
	   scanf("%d",&i);
	   if (i>random){
	   	printf ("Too big\n");
	   	cnt++;
	   }else if(i<random){
	   	if(i<0){printf("Game Over\n");
	   	    goto out;
		   }else {printf("Too small\n");
		   cnt++;
		   }
	   }else if(i=random){
	   	cnt++;
	   	if(cnt==1){printf("Bingo!");
	   	    goto out;
		   }else if (cnt<=3){printf("Lucky You!");
		    goto out;
	       }else {printf("Good Guess!");
	        goto out;
		   }
     	}  
	
		
	}while (cnt<max); 
		printf("Game Over");
    out:
	return 0;
}

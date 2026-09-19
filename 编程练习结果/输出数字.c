#include <stdio.h>
int main()
{
    int x;
    int y;
    int sum;
    int cnt=0;
	scanf("%d",&x);
	
	if ( x<0 ){
		printf ("fu ");
		x*=-1; 
	}	
	do{
		y=x%10;
		x/=10;
		sum=sum*10+y;
		cnt++;
	}while(x!=0);
//	printf("%d %d",sum,cnt); 
    do{
    	y=sum%10;
    	sum/=10;
    	if(y==0){
    		printf("ling");
		}else if(y==1){
			printf("yi"); 
		}else if(y==2){
			printf("er");
		}else if(y==3){
			printf("san");
		}else if(y==4){
			printf("si");
		}else if(y==5){
			printf("wu");
		}else if(y==6){
			printf("liu");
		}else if(y==7){
			printf("qi");
		}else if(y==8){
			printf("ba");
		}else if(y==9){
			printf("jiu");
		}
    	cnt--;
    	if (cnt!=0){
    		printf(" ");
		}
		
	}while(cnt!=0);
	
	
	
	return 0;
}

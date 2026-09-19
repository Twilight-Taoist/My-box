#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	int i,j,k;
	int cnt=0;
	
	for (i=a;i<=a+3;i++){
		for (j=a;j<=a+3;j++){
			for (k=a;k<=a+3;k++){
				if(i!=j){
					if(i!=k){
						if(j!=k){
							printf ("%d%d%d",i,j,k);
							cnt++;
							if (cnt==6){
								printf ("\n");
								cnt=0;
							}else{
								printf(" ");
							}
						}
					}
				}
			}
		}
	}
	
	
	
	return 0;
}


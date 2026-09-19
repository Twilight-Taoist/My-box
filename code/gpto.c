#include <stdio.h>

int main()
{
	int a=0;
	int one,two,five;
	int key=1;
	
	scanf("%d",&a);
	for (one=1; one<a*10; one++){
		for (two=1; two<a*10/2; two++){
			for (five=1; five<a*10/5;five++){
				if ( one+two*2+five*5==a*10){
					printf ("%d %d %d\n",one,two,five);
					goto out;
					/*key=0;
					break;*/
				}
			}
			//if (key==0) break;
		}
		//if (key==0) break;
	}
out:   
    return 0;
		
}

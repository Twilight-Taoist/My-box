#include <stdio.h>

int main(void)
{
    char word1[100]="shuki";
    char word2[100]="daishuki";
    char word3[100]="kirai";
    char word4[100]=" ";
//    printf ("%s %s %s ",word1,word2,word3);
    int n;
    int s;
    int i;
    int j;

    scanf ("%d %d",&n,&s);
    for ( i=0 ; i<n ; i++){
        scanf ("%s", word4);
        for ( j=0 ; i<2 ; i++ ){
            if ( word4[i]==word1[i] ){
                s++;              
            }else if( word4[i]==word2[i] ){
                s+=2;
            }else if ( word4[i]==word3[i] ){
                if ( s<0 ){
                    s=s;
                }else { s=0; }
            }else { s-=1; }
        }
    }
    if (s>0){
        printf ("%d",s);
    }else { printf("%s",word1); }
    return 0;
}

#include <stdio.h>
int gcd(int x,int y){
    return(x%y)?gcd(y,x%y):y;
}
int main(void){
    int K,x;
    long sum=0;
    scanf("%d",&K);
    for(int i=1; i<=K; i++){
        for(int j=i; j<=K; j++){
            x=gcd(j,i);
            for(int l=j; l<=K; l++){
                if(i!=j&&j!=l)
                    sum+=gcd(l,x)*6;
                else if(i!=j||j!=l)
                    sum+=gcd(l,x)*3;
                else
                    sum+=x;
            }
        }
    }
    printf("%ld",sum);
}

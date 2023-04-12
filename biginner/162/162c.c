#include <stdio.h>

long long gcd(long long x,long long y){
  return (x%y)?gcd(y,x%y):y;
}

int main(void){
  long long K;
  long long sum=0;
  scanf("%lld",&K);
  for(long long a=1;a<=K;a++){
    for(long long b=1;b<=K;b++){
      for(long long c=1;c<=K;c++){
        sum += gcd(gcd(a,b),c);
      }    
    }
  }
  printf("%lld\n",sum);
  return 0;
}

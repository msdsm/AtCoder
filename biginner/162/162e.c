#include <stdio.h>
#define mod 1000000007

long long gcd(long long a,long long b){
  return (a%b)?gcd(b,a%b):b;
}

long long rem(long long x,long long y){
  return x%y;
}

int main(void){
  long long mod,N,K,sum=0;
  scanf("%lld %lld",&N,&K);
  long long A[N];
  for(long long i=0;i<N;i++){
    sum += gcd(long)
  }







  printf("%lld",rem(sum,mod));
}

#include <stdio.h>
#define mod 1000000007
#define zero 0
typedef long long ll;

ll incsum(ll i,ll j){
  ll sum;
  sum = (j*(j+1))/2 - (i*(i-1))/2 ;
  return sum;
}

ll count(n,k){
  ll cnt;
  cnt = incsum(n-k+1,n) - incsum(zero,k-1) + 1 ;
  return cnt;
}

int main(void){
  ll num,k;
  ll sum=0;
  scanf("%lld",&num);
  scanf("%lld",&k);
  for(int i=k;i<=num;i++){
    sum += count(num,i);
  }
  printf("%lld",sum%mod);
  return 0;
}

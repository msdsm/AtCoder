#include <stdio.h>
typedef long long ll;
ll min(ll x,ll y){
  return (x>y)?y:x;
}

ll quotient(ll x,ll y){
  ll z = x%y;
  return z;
}

int main(void){
  ll N,K;
  scanf("%lld",&N);
  scanf("%lld",&K);
  printf("%lld",min(quotient(N,K),K-quotient(N,K)));
  return 0;
}

#include <stdio.h>
typedef long long ll;
 
void seq(ll num,ll a[],ll b[]){
  for(int i=0;i<num-1;i++){
    b[a[i]-1]++;
  }
  return ;
}
 
int main(void){
  ll num;
  scanf("%lld",&num);
  ll a[num-1];
  ll b[num];
  for(int i=0;i<num;i++){
    b[i]=0;
  }
  for(int i=0;i<num-1;i++){
  scanf("%lld",&a[i]);
  }
  seq(num,a,b);
  for(int i=0;i<num;i++){
  printf("%lld\n",b[i]);
  }
  return 0;
}

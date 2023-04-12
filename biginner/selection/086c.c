#include <stdio.h>
#define rep(a,i,n) for(i=a;i<n;i++)
typedef long long ll;

ll i;

ll diff(ll x,ll y){
  return (x>y)?(x-y):(y-x);
}

void judge(ll t[],ll u[],ll v[],ll n){
  i = 0;
  while(i<n && i>=0){
    ll lag = t[i+1]-t[i];
    ll tmp = diff(u[i+1],u[i]) + diff(v[i+1],v[i]);
    if(tmp<=lag && tmp%2==lag%2){
      i++;
    }else{
      i = -1;break;
    }
     }
  if(i == -1){
    printf("No\n");
  }else{
  printf("Yes\n");
  }
}

int main(void){
  ll num;
  scanf("%lld",&num);
  ll time[num+1],x[num+1],y[num+1];
  time[0]=x[0]=y[0]=0;
  rep(1,i,num+1){
    scanf("%lld %lld %lld",&time[i],&x[i],&y[i]); 
  }
  judge(time,x,y,num);
  return 0;
}

#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll f(ll num){
	ll cnt=0;
	while(num){
		num/=10;
		cnt++;
	}
	return cnt;
}

int main(){
	ll n;
	cin >> n;
	ll ans,cnt=0;
	arep(1,i,sqrt(n)+1){
		if(n%i==0){
			if(cnt==0){
				cnt++;
				ans=f(n/i);
			}else{
				if(ans>f(n/i))
					ans=f(n/i);
			}
		}
	}
	cout << ans << endl;
}
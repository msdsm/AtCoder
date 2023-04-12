#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll ans;

int main(){
	ll x,k,d;
	cin >> x >> k >> d;
	ll q = x/d;
	ll r = x%d;
	ans = x;
	if(x>0){
		if((k-q)>=0){
			if((k-q)%2==0)
				ans = r;
			else
				ans = r-d;
		}else{
			rep(i,k){
				ans-=d;
			}
		}
	}else{
		if((k+q)>=0){
			if((k-q)%2==0)
				ans = r;
			else
				ans = r+d;
		}else{
			rep(i,k){
				ans+=d;
			}
		}
	}
	cout << abs(ans) << endl;
}
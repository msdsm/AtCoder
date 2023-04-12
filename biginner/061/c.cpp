#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll cnt[100010];

int main(){
	ll n,k;
	cin >> n >> k;
	rep(i,n){
		ll a,b;
		cin >> a >> b;
		cnt[a]+=b;
	}
	ll sum=0;
	arep(1,i,100010){
		sum+=cnt[i];
		if(sum>=k){
			cout << i << endl;
			return 0;
		}
	}
}
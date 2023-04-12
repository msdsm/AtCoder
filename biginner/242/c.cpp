//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
#define fst first
#define snd second
#define pcin(x,n) for(ll i=0;i<(n);i++)cin>>x[i].fst>>x[i].snd;
#define pdebug(x) cout << '(' << x.fst << ',' << x.snd << ")\n";
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll f(ll x){
	if(x==0||x==8)
		return 2;
	else
		return 3;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	vector<int> cnt(9,1),tmp(9);
	ll ans = 1;
	ll mod = 998244353 ;
	//ll radix = 1;
	rep(i,n){
		rep(j,9){
			//ans += cnt[j]%mod*(j+1)%mod*radix%mod;
			ans += cnt[j]%mod*f(j)%mod-1;
			tmp[j]=0;
		}
		rep(j,9){
			if(j-1>=0){
				tmp[j-1] += cnt[j]%mod;
				tmp[j-1]%=mod;
			}
			if(j+1<9){
				tmp[j+1] += cnt[j]%mod;
				tmp[j+1]%=mod;
			}
		}
		rep(j,9){
			cnt[j] = tmp[j];
		}
		//radix *= 10;
		//radix%=mod;
	}
	cout << ans << endl;
}
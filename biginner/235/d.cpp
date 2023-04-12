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


ll ans;

ll digit(ll x){
	ll cnt = 0;
	while(x){
		x/=10;
		cnt++;
	}
	return cnt;
}


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll a,n;
	cin >> a >> n;
	while(n!=1){
		if(n%a==0){
			n/=a;
		}else{
			ll tmp = n/powl(10,digit(n)-1);
			ll tmp2 = n%static_cast<ll>(powl(10,digit(n)-1));
			n = tmp + 10*tmp2;
		}
		ans++;
		cout << ans << endl;
		cout << n << endl;
		if(ans>10){
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans << endl;
}
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

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll x,a,d,n;
	cin >> x >> a >> d >> n;
	if(d==0){
		cout << abs(a-x) << endl;
		return 0;
	}
	ll tmp = (x-a)/d+1;
	ll ans = numeric_limits<ll>::max();
	if(tmp<1){
		cout << abs(a-x) << endl;
		return 0;
	}
	if(tmp>n){
		cout << abs(x-(a+d*(n-1))) << endl;
		return 0;
	}
	if(tmp>=1 && tmp<=n)
		ans = min(ans,abs(a+d*(tmp-1)-x));
	if(tmp>1)
		ans = min(ans,abs(a+d*(tmp-2)-x));
	if(tmp < n)
		ans = min(ans,abs(a+d*tmp-x));
	cout << ans << endl;
}
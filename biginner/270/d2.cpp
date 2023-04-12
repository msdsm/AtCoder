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
	ll n,k;
	cin >> n >> k;
	vector<ll> a(k);
	cinf(a,k);
	ll ans = 0;
	ll sum = n;
	ll index;
	ll max = -1;
	while(sum){
		max = -1;
		index = 0;
		rep(i,k){
			ll tmp = a[i]*(sum/(2*a[i]));
			if(sum%(2*a[i]) >= a[i])
				tmp+=a[i];
			if(tmp>=max){
				index = i;
				max = tmp;
			}
		}
		sum -= a[index];
		ans += a[index];
		max = -1;
		index = 0;
		if(sum==0)
			break;
		rep(i,k){
			ll tmp = a[i]*(sum/(2*a[i]));
			if(sum%(2*a[i]) >= a[i])
				tmp+=a[i];
			if(tmp>=max){
				index = i;
				max = tmp;
			}
		}
		sum -= a[index];
	}
	cout << ans << endl;
}
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
	ll n,m;
	cin >> n >> m;
	vector<ll> a(n),b(m);
	cinf(a,n);
	cinf(b,m);
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	ll min = abs(a[0]-b[0]);
	rep(i,n){
		ll num = lower_bound(b.begin(),b.end(),a[i])-b.begin();
		ll tmp = abs(a[i]-b[num]);
		if(tmp<min)min=tmp;
		if(num>0){
			tmp = abs(a[i]-b[num-1]);
			if(tmp<min)min=tmp;
		}
	}
	cout << min << endl;
}
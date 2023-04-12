
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

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin>>n;
	vector<ll> a(n),b(n),c(n);
	cinf(a,n);cinf(b,n);cinf(c,n);
	vector<ll> cnt1(n,0),cnt2(n,0),cnt3(n,0);
	rep(i,n){
		cnt1[a[i]-1]++;
		cnt2[b[i]-1]++;
		cnt3[c[i]-1]++;
	}
	rep(i,n)ans+=(cnt1[b[i]-1]/**cnt2[b[i]-1]*/*cnt3[i]);
	cout << ans << endl;
}
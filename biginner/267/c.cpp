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
	ll n;
	cin >> n;
	vector<ll> a(n);
	cinf(a,n);
	vector<ll> b(n);
	rep(i,n){
		b[i] = (i+1)*a[i];
	}
	vector<ll> s(n);
	s[0]=b[0];
	rep2(1,i,n){
		s[i]=s[i-1]+b[i];
	}
	ll l = 0;
	ll r = n-1;
	ll tmp = numeric_limits<ll>::min();
	rep(i,n-1){
		if(tmp<s[n-i-1]){
			r = n-i-1;
		}
	}
}
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
	vector<string> s(10);
	cinf(s,10);
	ll a = 10;
	ll b = -1;
	ll c = 10;
	ll d = -1;
	rep(i,10){
		rep(j,10){
			if(s[i][j]=='#'){
				a = min(a,i);
				b = max(b,i);
				c = min(c,j);
				d = max(d,j);
			}
		}
	}
	cout << a+1 << ' ' << b+1 << endl;
	cout << c+1 << ' ' << d+1 << endl;
}
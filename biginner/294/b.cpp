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
	ll h,w;
	cin >> h >> w;
	vector<vector<ll> > a(h);
	rep(i,h)a[i].resize(w);
	rep(i,h){
		rep(j,w){
			cin >> a[i][j];
		}
	}
	vector<string> s(h);
	rep(i,h){
		rep(j,w){
			if(a[i][j]==0)
				s[i].push_back('.');
			else
				s[i].push_back(static_cast<char>('A'+a[i][j]-1));
		}
	}
	rep(i,h)cout << s[i] << endl;
}
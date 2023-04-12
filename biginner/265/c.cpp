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
	vector<vector<char> > g(h);
	rep(i,h)g[i].resize(w);
	rep(i,h){
		rep(j,w){
			cin >> g[i][j];
		}
	}
	ll i = 0;
	ll j = 0;
	rep(tt, h*w+10){
		if(g[i][j]=='U'){
			if(i>0){
				i--;
				continue;
			}else{
				cout << i+1 << ' ' << j+1 << endl;
				return 0;
			}
		}

		if(g[i][j]=='D'){
			if(i+1<h){
				i++;
				continue;
			}else{
				cout << i+1 << ' ' << j+1 << endl;
				return 0;
			}
		}

		if(g[i][j]=='L'){
			if(j>0){
				j--;
				continue;
			}else{
				cout << i+1 << ' ' << j+1 << endl;
				return 0;
			}
		}

		if(g[i][j]=='R'){
			if(j+1<w){
				j++;
				continue;
			}else{
				cout << i+1 << ' ' << j+1 << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
}
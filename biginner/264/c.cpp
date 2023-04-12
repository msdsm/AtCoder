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
	ll h1,w1;
	cin >> h1 >> w1;
	vector<vector<ll> > a(h1);
	rep(i,h1)a[i].resize(w1);
	rep(i,h1){
		rep(j,w1){
			cin >> a[i][j];
		}
	}
	ll h2,w2;
	cin >> h2 >> w2;
	vector<vector<ll> > b(h2);
	rep(i,h2)b[i].resize(w2);
	rep(i,h2){
		rep(j,w2){
			cin >> b[i][j];
		}
	}
	for(ll bit1 = 0; bit1 < (1<<h1); bit1++){
		for(ll bit2 = 0; bit2 < (1<<w1); bit2++){
			ll h=0;
			ll w=0;
			vector<ll> idh,idw;
			rep(i,h1){
				if(bit1 & (1<<i)){
					continue;
				}else{
					h++;
					idh.push_back(i);
				}
			}
			rep(i,w1){
				if(bit2 & (1<<i)){
					continue;
				}else{
					w++;
					idw.push_back(i);
				}
			}
			if(h!=h2 || w!=w2)
				continue;
			vector<vector<ll> > tmp(h);
			rep(i,h)tmp[i].resize(w);
			rep(i,idh.size()){
				rep(j,idw.size()){
					tmp[i][j] = a[idh[i]][idw[j]];
				}
			}
			bool flag = true;
			rep(i,h){
				rep(j,w){
					if(tmp[i][j]!=b[i][j])
						flag = false;
				}
			}
			if(flag){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}
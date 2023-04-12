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
	ll n,x;
	cin >> n >> x;
	vector<pll> p(n);
	pcin(p,n);
	vector<vector<bool> > b(n);
	rep(i,n){
		b[i].resize(10000,false);
	}
	b[0][p[0].fst]=true;
	b[0][p[0].snd]=true;
	rep2(1,i,n){
		rep(j,10000){
			if(b[i-1][j]){
				b[i][j+p[i].fst]=true;
				b[i][j+p[i].snd]=true;
			}
		}
	}
	if(b[n-1][x])
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
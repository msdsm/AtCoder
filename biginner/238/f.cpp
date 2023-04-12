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
	ll n,K;
	cin >> n >> K;
	vector<pll> p(n);
	rep(i,n)cin>>p[i].fst;
	rep(i,n)cin>>p[i].snd;
	sort(p.begin(),p.end());
/*
	cout << "debug start" << endl;
	rep(i,N){
		cout << p[i].fst << ' '  << p[i].snd << endl;
	}
	cout << "debug end" << endl;
*/
	vector<ll> tmp(n,0);
	vector<vector<ll> > tmp2(n,tmp);
	vector<vector<vector<ll> > > dp(n,tmp2);
	rep(i,n){
		rep(j,n){
			rep(k,n){
				cout << dp[i][j][k] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
}
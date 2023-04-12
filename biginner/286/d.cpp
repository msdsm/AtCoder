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
	vector<ll> a(n),b(n);
	rep(i,n)cin>>a[i]>>b[i];
	vector<vector<bool> > dp(n);
	rep(i,n)dp[i].resize(x+1);
	rep(i,n)dp[i][0]=true;
	rep(j,b[0]+1){
		if(a[0]*j<x+1)
			dp[0][a[0]*j]=true;
	}
	rep(i,n-1){
		rep(j,x+1){
			if(!dp[i][j])continue;
			rep(k,b[i+1]+1){
				if(j+a[i+1]*k<x+1)
					dp[i+1][j+a[i+1]*k]=true;
			}
		}
	}
	if(dp[n-1][x])
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
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
	vector<string> s(n);
	cinf(s,n);
	vector<vector<bool> > dp(1<<n);
	rep(i, (1<<n)){
		dp[i].resize(n, false);
	}
	rep(j,n){
		dp[1<<j][j] = true;
	}
	rep2(1,i,(1<<n)){
		rep(j,n){
			if(dp[i][j]){
				rep(k,n){
					if((i&(1<<k))!=0)continue;
					if(s[j][s[j].length()-1]==s[k][0]){
						dp[i|(1<<k)][k] = true;
					}
				}
			}
		}
	}
	rep(i,(1<<n)){
		rep(j,n){
			cout << dp[i][j] << ' ';
		}cout<<endl;
	}
}
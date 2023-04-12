/*
TSP
bitDP O(n^2 * 2^n)
ラムダ式を使用する場合はg++-11でコンパイル
*/

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

ll inf = numeric_limits<ll>::max();

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	vector<ll> x(n),y(n),z(n);
	rep(i,n)cin>>x[i]>>y[i]>>z[i];
	ll bits = (1<<n);
	vector<vector<ll> > dp(n);
	rep(i,n)dp[i].resize(bits,inf);
	dp[0][0]=0;//使わない
	dp[0][1]=0;
	auto cost = [&](ll p1, ll p2){//p1→p2
		return abs(x[p2]-x[p1])+abs(y[p2]-y[p1])+max(ll(0),z[p2]-z[p1]);
	};
	rep(j,bits){
		rep(i,n){
			if(i==0&&j==0)
				continue;
			if(dp[i][j]==inf)continue;
			rep(k,n){
				if(i==k)continue;
				dp[k][j|(1<<k)] = min(dp[k][j|(1<<k)], dp[i][j]+cost(i,k));
			}
		}
	}
	rep(j,bits){
		rep(i,n){
			if(i==0&&j==0)
				continue;
			if(dp[i][j]==inf)continue;
			rep(k,n){
				if(i==k)continue;
				dp[k][j|(1<<k)] = min(dp[k][j|(1<<k)], dp[i][j]+cost(i,k));
			}
		}
	}
	rep(i,n){
		rep(j,bits){
			if(dp[i][j]==inf){
				cout << "inf" << ' ';
				continue;
			}
			cout << dp[i][j] << ' ';
		}cout<<endl;
	}
	cout << "debug end" << endl;
	cout << dp[0][bits-1] << endl;
}
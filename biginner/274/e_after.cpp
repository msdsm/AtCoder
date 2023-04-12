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

ld inf = numeric_limits<ld>::max();


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	vector<ll> x(n+m),y(n+m);
	rep(i,n+m)cin>>x[i]>>y[i];
	ll bits = (1<<m+n);
	ll mask = (1<<n)-1;//巡回都市確認
	ll mask2 = bits-mask-1;//宝の数
	vector<vector<ld> > dp(n+m);
	rep(i,n+m)dp[i].resize(bits, inf);
	auto d = [&](ll p1, ll p2){
		ll sum = (x[p2]-x[p1])*(x[p2]-x[p1])+(y[p2]-y[p1])*(y[p2]-y[p1]);
		return sqrt(sum);
	};
	dp[0][0]=inf;//使わない
	rep(i,m+n){//初期値
		dp[i][(1<<i)] = sqrt(x[i]*x[i]+y[i]*y[i]);
	}
	rep(j,bits){//集合
		rep(i,n+m){//現在地点　宝も都市
			if(i==0&&j==0)
				continue;
			if(dp[i][j]==inf)
				continue;
			ll v = __builtin_popcount(j&mask2);
/*
			cout << "debug start" << endl;
			cout << i << endl;
			cout << j << endl;
			cout << v << endl;
			cout << (j&mask2) << endl;
			cout << "debug end" << endl;
*/			
			
			rep(k,n+m){
				if(i==k)
					continue;
				dp[k][j|(1<<k)] = min(dp[k][j|(1<<k)],dp[i][j]+d(i,k)/(1<<v));
			}
		}
	}
	ld ans = inf;
	rep(i,n+m){
		rep(j,bits){		
			if((j&mask)==mask && dp[i][j]!=inf){//都市巡回済み
/*
			cout << "debug start" << endl;
			cout << bits << endl;
			cout << "debug end" << endl;
*/			
				ll v = __builtin_popcount(j&mask2);
				ans = min(ans, dp[i][j]+sqrt(x[i]*x[i]+y[i]*y[i])/(1<<v));
			}
		}
	}
/*
	cout << "debug start" << endl;
	rep(i,n+m){
		rep(j,bits){
			if(dp[i][j]==inf){
				cout << "inf" << "     ";
				continue;
			}
			cout << dp[i][j] << "     ";
		}cout<<endl;
	}
	cout << "debug end" << endl;
*/

	cout << ans << endl;
	//cout << inf << endl;
}
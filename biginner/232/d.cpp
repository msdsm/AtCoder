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
	vector<vector<char> > c(h);
	rep(i,h){
		c[i].resize(w);
		rep(j,w){
			cin >> c[i][j];
		}
	}
/*
	cout << "debug start" << endl;
	rep(i,h){
		rep(j,w){
			cout << c[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;
*/
	vector<vector<ll> > dp(h);
	rep(i,h)dp[i].resize(w);
	ll inf = -(h*w);
	dp[0][0]=1;
	rep2(1,i,h){
		if(c[i][0]=='.')
			dp[i][0]=dp[i-1][0]+1;
		else
			dp[i][0]=inf;
	}
	rep2(1,j,w){
		if(c[0][j]=='.')
			dp[0][j]=dp[0][j-1]+1;
		else
			dp[0][j]=inf;
	}
	rep2(1,i,h){
		rep2(1,j,w){
			if(c[i][j]=='#')
				dp[i][j]=inf;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1])+1;
		}
	}
	ll max = 1;
	rep(i,h)rep(j,w)if(max<dp[i][j])max=dp[i][j];
	cout << max << endl;
}
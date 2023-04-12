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

ll mod = 1e9+7;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	string s;
	cin >> s;
	ll n = s.length();
	ll dp[n+1][9];//sのi文字目まででchokudaiのj文字目まで選択する方法
	rep(i,n+1)rep(j,9)dp[i][j]=0;
	string t = "chokudai";
	rep2(1,j,9)dp[0][j]=0;
	rep(i,n+1)dp[i][0]=1;
	rep2(1,i,n+1){
		rep2(1,j,9){
			if(s[i-1]==t[j-1])
				dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
			else
				dp[i][j] = dp[i-1][j];
			dp[i][j]%=mod;
		}
	}
	cout << dp[n][8] << endl;
}
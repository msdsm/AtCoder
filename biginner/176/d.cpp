#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
#define min(a,b,c) ((a)>(b)?(b):(a)
#define min3(a,b,c) ((a)>min((b),(c))?min((b),(c)):(a))
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll dp[1001][1001];

ll min55(ll i,ll j){
	for(ll k=)
}

int main(){
	ll h,w;
	cin >> h >> w;
	ll ch,cw;
	cin >> ch >> cw;
	ll dh,dw;
	cin >> dh >> dw;
	char s[h][w];
	rep(i,h)rep(j,w)cin>>s[i][j];
	rep(i,h){
		rep(j,w){
			dp[i][j]=10000000;
		}
	}
	dp[ch-1][cw-1]=0;

	for(ll i=ch-1;i>=0;i--){
		for(ll j=cw-1;j>=0;j--){
			if(i==ch-1&&j==cw-1)continue;
			if(s[i][j]=='#'){
				dp[i][j]=min3(dp[i][j+1],dp[i+1][j],min55(i,j))
			}
		}
	}


	cout << dp[dh-1][dw-1] << endl;
}
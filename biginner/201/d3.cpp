//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	int h,w;
	cin >> h >> w;
	char a[h][w];
	int dp[h][w];
	rep(i,h)rep(j,w){
		cin>>a[i][j];
		dp[i][j]=0;
	}
	for(ll i=h-1;i>=0;i--){
		for(ll j=w-1;j>=0;j--){
			if(i==h-1&&j==w-1)
				continue;
			else if(i==h-1){
				if((i+j)%2==0)
					dp[i][j]=dp[i][j+1]+((a[i][j+1]=='+')?1:-1);
				else
					dp[i][j]=dp[i][j+1]-((a[i][j+1]=='+')?1:-1);
			}else if(j==w-1){
				if((i+j)%2==0)
					dp[i][j]=dp[i+1][j]+((a[i+1][j]=='+')?1:-1);
				else
					dp[i][j]=dp[i+1][j]-((a[i+1][j]=='+')?1:-1);
			}else{
				if((i+j)%2==0)
					dp[i][j]=max(
						dp[i][j+1]+((a[i][j+1]=='+')?1:-1),
						dp[i+1][j]+((a[i+1][j])=='+'?1:-1)
						);
				else
					dp[i][j]=min(
						dp[i][j+1]-((a[i][j+1]=='+')?1:-1),
						dp[i+1][j]-((a[i+1][j])=='+'?1:-1)
						);
			}
		}
	}
/*
	cout << "debug start" << endl;
	rep(i,h)rep(j,w){
		if(j==w-1)
			cout << dp[i][j] << endl;
		else
			cout << dp[i][j] << ' ';
	}
	cout << "debug end" << endl;
*/	
	
	if(dp[0][0]>0)
		cout << "Takahashi" << endl;
	else if(dp[0][0]<0)
		cout << "Aoki" << endl;
	else
		cout << "Draw" << endl;
}
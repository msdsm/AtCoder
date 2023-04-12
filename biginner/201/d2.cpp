
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

template <class Type>
Type max3(Type a,Type b,Type c){
	return max(a,b) > c ? max(a,b) : c;
}

pii dp[2010][2010];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	int h,w;
	cin >> h >> w;
	char a[h][w];
	rep(i,h)rep(j,w){
		cin>>a[i][j];
	}
	//cout << ((a[0][0]=='+')?1:-1) << endl;
	
	for(ll i=h-1;i>=0;i--){
		for(ll j=w-1;j>=0;j--){
			if(i==h-1&&j==w-1)
				continue;
			else if(i==h-1){
				if((i+j)%2==0){
					dp[i][j].first=dp[i][j+1].first+((a[i][j+1]=='+')?1:-1);
					dp[i][j].second=dp[i][j+1].second;
				}else{
					dp[i][j].second=dp[i][j+1].second+((a[i][j+1]=='+')?1:-1);
					dp[i][j].first=dp[i][j+1].first;
				}
			}
			else if(j==w-1){
				if((i+j)%2==0){
					dp[i][j].first=dp[i+1][j].first+((a[i+1][j]=='+')?1:-1);
					dp[i][j].second=dp[i+1][j].second;
				}else{
					dp[i][j].second=dp[i+1][j].second+((a[i+1][j]=='+')?1:-1);
					dp[i][j].first=dp[i+1][j].first;
				}
			}
			else if((i+j)%2==0){
				//青木のます
				dp[i][j].first = max(
					dp[i+1][j].first+((a[i+1][j]=='+')?1:-1),
					dp[i][j+1].first+((a[i][j+1]=='+')?1:-1)
					//dp[i+1][j+1].first+((a[i+1][j+1]=='+')?1:-1)
					);
				dp[i][j].second=max(
					dp[i+1][j].second,
					dp[i][j+1].second
					//dp[i+1][j+1].second
					);
			}else{
				//高橋のます
				dp[i][j].second=max(
					dp[i+1][j].second+((a[i+1][j]=='+')?1:-1),
					dp[i][j+1].second+((a[i][j+1]=='+')?1:-1)
					//dp[i+1][j+1].second+((a[i+1][j+1]=='+')?1:-1)
					);
				dp[i][j].first=max(
					dp[i+1][j].first,
					dp[i][j+1].first
					//dp[i+1][j+1].first
					);
			}
		}
	}

/*
	cout << "debug start" << endl;
	rep(i,h)rep(j,w){
		if(j==w-1)
			cout <<  '(' << dp[i][j].first << ',' << dp[i][j].second << ')' << endl;
		else
			cout <<  '(' << dp[i][j].first << ',' << dp[i][j].second << ')' <<' ';
	}
	cout << "debug end" << endl;
*/	
	
	
	if(dp[0][0].first<dp[0][0].second)
		cout << "Aoki" << endl;
	else if(dp[0][0].first>dp[0][0].second)
		cout << "Takahashi" << endl;
	else
		cout << "Draw" << endl;
}	
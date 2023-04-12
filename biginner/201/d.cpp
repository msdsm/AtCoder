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

ll cnt,cnta;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll h,w;
	cin >> h >> w;
	char a[h][w];
	rep(i,h){
		rep(j,w){
			cin >> a[i][j];
		}
	}
	rep(i,h){
		rep(j,w){
			if(i==0&&j==0)
				continue;
			if((i+j)%2==0)
				cnta+=(a[i][j]=='+'?1:0);
			else
				cnt+=(a[i][j]=='+'?1:0);
		}
	}
	if(cnta<cnt)
		cout << "Takahashi" << endl;
	else if(cnta==cnt)
		cout << "Draw" << endl;
	else
		cout << "Aoki" << endl;
}
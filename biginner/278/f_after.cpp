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
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	vector<string> s(n);
	cinf(s,n);
	vector<pll> info(n);
	rep(i,n){
		info[i].fst = s[i].front()-'a';
		info[i].snd = s[i].back()-'a';
	}
	vector<vector<bool> > dp(1<<n);
	rep(i,1<<n)dp[i].resize(26,false);

	rep2(1,i,1<<n){
		rep(c,26){
			rep(j,n){
				if((i&(1<<j))!=0 && info[j].fst==c){
					if(dp[i-(1<<j)][info[j].snd]==0){
						dp[i][c]=1;
					}else{
						dp[i][c]=0;
					}
				}else{
					dp[i][c]=0;
				}
			}
		}
	}


	cout << "debug start" << endl;
	rep(i,1<<n){
		rep(c,26){
			cout << dp[i][c] << ' ';
		}cout<<endl;
	}
	cout << "debug end" << endl;
	
	

	rep(c,26){
		if(dp[(1<<n)-1][c]){
			cout << "First" << endl;
			return 0;
		}
	}
	cout << "Second" << endl;
}
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

using P = pair<pll, ll>;//h,w,n

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	//map<P, ll> mp;
	ll H,W,N,h,w;
	cin >> H >> W >> N >> h >> w;
	vector<vector<vector<ll> > > dp(N);
	rep(n,N)dp[n].resize(H+1);
	rep(n,N){
		rep(i,H+1){
			dp[n][i].resize(W+1);
		}
	}
	vector<vector<ll> > a(H);
	rep(i,H)a[i].resize(W);
	rep(i,H){
		rep(j,W){
			cin >> a[i][j];
			a[i][j]--;
		}
	}

	//初期化
	rep(n,N){
		rep(i,H+1){
			dp[n][i][0]=0;
		}
	}
	rep(n,N){
		rep(j,W+1){
			dp[n][0][j]=0;
		}
	}

	//dp
	rep(n,N){
		rep2(1,i,H+1){
			rep2(1,j,W+1){
				dp[n][i][j] = dp[n][i-1][j]+dp[n][i][j-1]-dp[n][i-1][j-1];
				if(a[i-1][j-1]==n)
					dp[n][i][j]++;
			}
		}
	}

/*
	cout << "debug start" << endl;
	rep(i,H+1){
		rep(j,W+1){
			cout << dp[2][i][j] << ' ';
		}cout<<endl;
	}
	cout << "debug end" << endl;
*/
	vector<vector<ll> > ans(H-h+1);
	rep(k,H-h+1)ans[k].resize(W-w+1);
	rep(k,H-h+1){
		rep(l,W-w+1){
			vector<ll> cnt(N);
			rep(n,N){
				cnt[n] = dp[n][H][W]-dp[n][k+h][l+w]+dp[n][k+h][l]+dp[n][k][l+w]-dp[n][k][l]; 
			}
			rep(n,N){
				if(cnt[n]>0)
					ans[k][l]++;
			}
		}
	}
	rep(k,H-h+1){
		rep(l,W-w+1){
			cout << ans[k][l] << ' ';
		}cout<<endl;
	}
}
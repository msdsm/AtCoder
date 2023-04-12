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
	ll n;
	cin >> n;
	char s[n][n];
	rep(i,n){
		rep(j,n){
			cin >> s[i][j];
		}
	}
	//縦
	rep(i,n){
		rep(j,n){
			if(i+5<=n-1){
				int cnt=0;
				rep(k,6){
					if(s[i+k][j]=='#')
						cnt++;
					if(cnt>=4){
						cout << "Yes" << endl;
						return 0;
					}
				}
			}else{
				continue;
			}
		}
	}
	//横
	rep(i,n){
		rep(j,n){
			if(j+5<=n-1){
				int cnt=0;
				rep(k,6){
					if(s[i][j+k]=='#')
						cnt++;
					if(cnt>=4){
						cout << "Yes" << endl;
						return 0;
					}
				}
			}else{
				continue;
			}
		}
	}
	//斜め右下
	rep(i,n){
		rep(j,n){
			if(i+5<=n-1&&j+5<=n-1){
				int cnt=0;
				rep(k,6){
					if(s[i+k][j+k]=='#')
						cnt++;
					if(cnt>=4){
						cout << "Yes" << endl;
						return 0;
					}
				}
			}else{
				continue;
			}
		}
	}
	//斜め左下
	rep(i,n){
		rep(j,n){
			if(i+5<=n-1&&j-5>=0){
				int cnt=0;
				rep(k,6){
					if(s[i+k][j-k]=='#')
						cnt++;
					if(cnt>=4){
						cout << "Yes" << endl;
						return 0;
					}
				}
			}else{
				continue;
			}
		}
	}
	cout << "No" << endl;
}
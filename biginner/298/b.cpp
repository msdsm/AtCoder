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
	vector<vector<ll> > a(n),b(n),tmp(n);
	rep(i,n){
		a[i].resize(n);
		b[i].resize(n);
		tmp[i].resize(n);
	}
	rep(i,n){
		rep(j,n){
			cin >> a[i][j];
			tmp[i][j] = a[i][j];
		}
	}
	rep(i,n){
		rep(j,n){
			cin >> b[i][j];
		}
	}
	bool flag = true;
	rep(i,n){
		rep(j,n){
			if(a[i][j]==1){
				if(b[i][j]!=1){
					flag = false;

				}
			}
		}
	}
	if(flag){
		cout << "Yes" << endl;
		return 0;
	}
	ll t = 3;
	while(t--){
		rep(i,n){
			rep(j,n){
				a[i][j] = tmp[n-1-j][i];
			}
		}

		flag = true;
		rep(i,n){
			rep(j,n){
				if(a[i][j]==1){
					if(b[i][j]!=1){
						flag = false;
					}
				}
			}
		}
		if(flag){
			cout << "Yes" << endl;
			return 0;
		}
		rep(i,n){
			rep(j,n){
				tmp[i][j] = a[i][j];
			}
		}
	}
	cout << "No" << endl;
}
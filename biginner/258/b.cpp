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

int dx[8]={1,1,0,-1,-1,-1, 0,1};
int dy[8]={0,1,1, 1, 0,-1,-1,-1};

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	vector<vector<char> > a(n);
	rep(i,n)a[i].resize(n);
	rep(i,n){
		rep(j,n){
			cin >> a[i][j];
		}
	}
	vector<vector<vector<ll> > > sum(n);
	rep(i,n)sum[i].resize(n);

	rep(i,n){
		rep(j,n){
			sum[i][j].resize(8);
		}
	}

	rep(i,n){
		rep(j,n){
			//cout << i << ' ' << j << endl;
			rep(k,8){
				string s;
				ll x = i;
				ll y = j;
				s.push_back(a[x][y]);
				rep(tttt,n-1){
					x += dx[k];
					y += dy[k];
					if(x==n)
						x=0;
					else if(x==-1)
						x=n-1;
					if(y==n)
						y=0;
					else if(y==-1)
						y=n-1;
					s.push_back(a[x][y]);
				}
				sum[i][j][k] = stol(s);
			}
		}
	}

	ll ans = 0;
	rep(i,n){
		rep(j,n){
			rep(k,8){
				if(ans<sum[i][j][k])
					ans = sum[i][j][k];
			}
		}
	}
	cout << ans << endl;
}
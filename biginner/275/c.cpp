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

ll ans;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	vector<string> s(9);
	rep(i,9)cin>>s[i];
	rep(i,9){
		rep(j,9){
			rep(k,9){
				rep(l,9){
					ll dx = k;
					ll dy = l;
					if(dx==0||dy==0)continue;
					if(j-dy>=0&&i+dx+dy<=8&&j+dx<=8){
						if(s[i][j]=='.')continue;
						if(s[i+dx][j-dy]=='.')continue;
						if(s[i+dx+dy][j-dy+dx]=='.')continue;
						if(s[i+dy][j+dx]=='.')continue;
						ans++;
					}
				}
			}
		}
	}
	rep(i,9){
		rep(j,9){
			rep(k,9){
				if(k==0)continue;
				if(i+k<=8&&j+k<=8){
					if(s[i][j]=='.')continue;
					if(s[i+k][j]=='.')continue;
					if(s[i+k][j+k]=='.')continue;
					if(s[i][j+k]=='.')continue;
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}
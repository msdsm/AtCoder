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
	ll h,w;
	cin >> h >> w;
	vector<vector<char> > a(h),b(h),tmp(h);
	rep(i,h){
		a[i].resize(w);
		b[i].resize(w);
		tmp[i].resize(w);
	}
	rep(i,h)rep(j,w)cin>>a[i][j];
	rep(i,h)rep(j,w)cin>>b[i][j];

	rep(s,h+1){//縦
		if(s!=0){
			rep(j,w){
				rep(i,h-1){
					tmp[i][j] = a[i+1][j];
				}
				tmp[h-1][j] = a[0][j];
			}

			//保存
			rep(i,h)rep(j,w)a[i][j]=tmp[i][j];
		}
		rep(t,w+1){//横
			if(s!=0){
				rep(i,h){
					rep(j,w-1){
						tmp[i][j] = a[i][j+1];
					}
					tmp[i][w-1] = a[i][0];
				}

			//保存
				rep(i,h)rep(j,w)a[i][j]=tmp[i][j];
			}
			//tmpが変形後
			//確認
			bool flag = true;
			rep(i,h){
				rep(j,w){
					if(a[i][j]==b[i][j])
						continue;
					else
						flag = false;
				}
			}
			if(flag){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}
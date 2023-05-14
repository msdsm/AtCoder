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

ll dx[4]={1,1,-1,-1};
ll dy[4]={1,-1,1,-1};

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll h,w;
	cin >> h >> w;
	vector<vector<char> > c(h);
	rep(i,h)c[i].resize(w);
	rep(i,h)rep(j,w)cin>>c[i][j];
	vector<ll> ans(min(h,w));
	rep(i,h){
		rep(j,w){
/*
			cout << "debug start i,j" << endl;
			cout << i << ' ' << j << endl;
			cout << "debug end" << endl;
*/			
			
			char now = c[i][j];
			if(now=='.'){
				continue;
			}else{
				//四方全探索
				vector<ll> tmp(4);
				ll size = min(h,w);
				rep(t,4){
					ll x = i+dx[t];
					ll y = j+dy[t];
/*
					cout << "debug start x,y" << endl;
					cout << x << endl;
					cout << y << endl;
					cout << "debug end" << endl;
*/					
					
					while(x>=0 && x<h && y>=0 && y<w && c[x][y]=='#'){
						tmp[t]++;
						x += dx[t];
						y += dy[t];
					}
/*
					cout << "debug start tmp" << endl;
					cout << t << endl;
					cout << tmp[t] << endl;
					cout << "debug end" << endl;
*/					
					
					if(tmp[t]<size)
						size = tmp[t];
				}
				if(size>0)
					ans[size-1]++;
			}
		}
	}
	rep(i,min(h,w)){
		cout << ans[i] << ' ';
	}cout<<endl;
}
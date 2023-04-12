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

using P = pair<pll,ll>;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	vector<P> p(n);
	rep(i,n){
		ll x,y,po;
		cin >> x >> y >> po;
		p[i].fst.fst = x;
		p[i].fst.snd = y;
		p[i].snd = po;
	}
	vector<vector<ll> > path(n);
	rep(i,n)path[i].resize(n);
	rep(i,n){
		rep(j,n){
			if(i==j)
				path[i][j]=0;
			else{
				//path[i][j]=ceil((abs(p[i].fst.fst-p[j].fst.fst)+abs(p[i].fst.snd-p[j].fst.snd))/p[i].snd);
				ll child = abs(p[i].fst.fst-p[j].fst.fst)+abs(p[i].fst.snd-p[j].fst.snd);
				ll mother = p[i].snd;
				if(child%mother==0)
					path[i][j] = child/mother;
				else
					path[i][j] = child/mother + 1;
			}
		}
	}

	//ワーシャルフロイド
	vector<vector<ll> > d(n);
	rep(i,n)d[i].resize(n);
	rep(i,n){
		rep(j,n){
			d[i][j]=path[i][j];
		}
	}
	rep(k,n){
		rep(i,n){
			rep(j,n){
				if(d[i][j] > max(d[i][k],d[k][j]))
					d[i][j] = max(d[i][k],d[k][j]);
			}
		}
	}
/*
	cout << "debug start path" << endl;
	rep(i,n){
		rep(j,n){
			cout << path[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;
	cout << endl;
	cout << "debug start d" << endl;
	rep(i,n){
		rep(j,n){
			cout << d[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;
*/	

	ll ans = numeric_limits<ll>::max();
	rep(i,n){
		ll tmp = d[i][0];
		rep(j,n){
			if(tmp<d[i][j])
				tmp=d[i][j];
		}
		if(ans>tmp)
			ans = tmp;
	}
	cout << ans << endl;
}
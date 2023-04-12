#pragma GCC optimize("Ofast")
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

ld ans = numeric_limits<ld>::max();

ld d(ll x1, ll y1, ll x2, ll y2){
	ll sum = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	return sqrt(sum);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	vector<ll> x(n),y(n);
	rep(i,n)cin>>x[i]>>y[i];
	vector<ll> p(m),q(m);
	rep(i,m)cin>>p[i]>>q[i];
	vector<ll> v(n+m);
	rep(i,n+m)v[i]=i;
	do{
		ld sum = 0.0;
		ll px = 0;
		ll py = 0;
		ll sp = 1;
		rep(i,n+m){
			if(v[i]>=n){//宝
				ll nx = p[v[i]-n];
				ll ny = q[v[i]-n];
				sum += d(px,py,nx,ny)/sp;
				sp *= 2;
				px = nx;
				py = ny;
			}else{//都市
				ll nx = x[v[i]];
				ll ny = y[v[i]];
				sum += d(px,py,nx,ny)/sp;
				px = nx;
				py = ny;
			}
		}
		sum += d(px,py,ll(0),ll(0))/sp;
		if(sum<ans)
			ans = sum;
	}while(next_permutation(v.begin(),v.end()));
	cout << ans << endl;
}
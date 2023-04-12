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
	ll n,x;
	cin >> n >> x;
	vector<ll> l(n);
	vector<vector<ll> > a(n);
	rep(i,n){
		cin >> l[i];
		rep(j,l[i]){
			ll tmp;
			cin >> tmp;
			a[i].push_back(tmp);
		}
	}
	stack<pll> open;
	//vector<pll> closed;
	rep(i,l[0]){
		open.push(pll(1,a[0][i]));//深さ、現在の積
	}
	while(!open.empty()){
		pll tmp = open.top();
		open.pop();
		if(tmp.fst==n){
			if(tmp.snd==x){
				ans++;
			}
		}else{
			rep(i,l[tmp.fst]){
				if(tmp.snd*a[tmp.fst][i]<=x)
					open.push(pll(tmp.fst+1,tmp.snd*a[tmp.fst][i]));
			}
		}
	}
	cout << ans << endl;
}
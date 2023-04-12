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
	ll m;
	cin >> m;
	vector<set<ll> > vs(m);
	rep(i,m){
		ll k;
		cin >> k;
		rep(j,k){
			ll x;
			cin >> x;
			x--;
			vs[i].insert(x);
		}
	}
	rep(i,n){
		rep2(i+1,j,n){
			bool flag = false;
			rep(k,m){
				if(vs[k].count(i)>0&&vs[k].count(j)>0){
					flag = true;
					break;
				}
			}
			if(!flag){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}
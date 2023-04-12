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
	ll n,k;
	cin >> n >> k;
	vector<ll> p(n);
	cinf(p,n);
	rep(i,n)p[i]--;
	vector<ll> ans(n,-1);
	if(k==1){
		rep(i,n){
			ans[p[i]] = i+1;
		}
		rep(i,n){
			cout << ans[i] << endl;
		}
		return 0;
	}
	vector<deque<ll> > d;
	vector<ll> c;
	rep(i,n){
		ll tmp = p[i];
		//auto itr = lower_bound(c.begin(),c.end(),tmp);
		ll idx = lower_bound(c.begin(),c.end(),tmp)-c.begin();
		if(idx==c.size()){
			c.push_back(tmp);
			deque<ll> dd;
			dd.push_front(tmp);
			d.push_back(dd);
		}else{
			c[idx] = tmp;
			d[idx].push_front(tmp);
			if(d[idx].size()==k){
				rep(j,d[idx].size()){
					ans[d[idx][j]]=i+1;
				}
				c.erase(c.begin()+idx);
				d.erase(d.begin()+idx);
			}
		}
	}
	rep(i,n){
		cout << ans[i] << endl;
	}
}
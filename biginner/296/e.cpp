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
	vector<ll> a(n);
	cinf(a,n);
	rep(i,n)a[i]--;
	vector<vector<ll> > p(n);
	vector<ll> ind(n);
	rep(i,n){
		p[i].push_back(a[i]);
		ind[a[i]]++;
	}
	queue<ll> q;
	set<ll> ao;
	rep(i,n){
		if(ind[i]==0){
			q.push(i);
			ao.insert(i);
		}
	}
	while(!q.empty()){
		ll tmp = q.front();
		q.pop();
		rep(i,p[tmp].size()){
			ll next = p[tmp][i];
			ind[next]--;
			if(ind[next]==0){
				q.push(next);
				ao.insert(next);
			}
		}
	}
	ll ans = 0;
	rep(i,n){
		if(ao.count(i)==0)
			ans++;
	}
	cout << ans << endl;
}
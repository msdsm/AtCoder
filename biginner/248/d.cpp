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
	vector<vector<ll> > index(n+1);
	cinf(a,n);
	rep(i,n){
		index[a[i]].push_back(i);
	}
	ll Q;
	cin >> Q;
	while(Q--){
		ll l,r,x;
		cin >> l >> r >> x;
		l--;r--;
		if(index[x].size()==0){
			cout << 0 << endl;
			continue;
		}
		if(l>index[x][index[x].size()-1]){
			cout << 0 << endl;
			continue;
		}
		if(r<index[x][0]){
			cout << 0 << endl;
			continue;
		}
		ll tmp = lower_bound(index[x].begin(),index[x].end(),l) - index[x].begin();
		ll tmp2 = lower_bound(index[x].begin(),index[x].end(),r) - index[x].begin();
		if(*(lower_bound(index[x].begin(),index[x].end(),r))==r)
			cout << tmp2-tmp+1 << endl;
		else
			cout << tmp2-tmp << endl;
	}
}
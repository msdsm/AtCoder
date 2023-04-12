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
	priority_queue<pll, vector<pll>, greater<pll> > q;
	ll n;
	cin >> n;
	vector<ll> s(n),t(n),ans(n);
	cinf(s,n);
	cinf(t,n);
	set<ll> st;
	rep(i,n)st.insert(i);
	rep(i,n)q.push(pll(t[i],i));
	while(!st.empty()){
		pll p = q.top();
		q.pop();
		if(st.count(p.snd)>0){
			ans[p.snd]=p.fst;
			st.erase(p.snd);
		}
		q.push(pll(p.fst+s[p.snd],(p.snd+1)%n));
	}
	rep(i,n)cout << ans[i] << endl;
}
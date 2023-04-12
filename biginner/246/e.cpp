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
	pll a,b;
	cin >> a.fst >> a.snd;
	cin >> b.fst >> b.snd;
	a.fst--;a.snd--;
	b.fst--;b.snd--;
	vector<string> s(n);
	rep(i,n)cin>>s[i];
	if((a.fst+a.snd)%2!=(b.fst+b.snd)%2){
		cout << -1 << endl;
		return 0;
	}
	vector<vector<bool> > v(n);
	rep(i,n)v[i].resize(n,false);
	queue<pair<pll,ll> > q;
	q.push(pair<pll,ll>(a,0));
	while(!q.empty()){
		pair<pll,ll> tmp = q.front();
		pll p = tmp.fst;
		ll cnt = tmp.snd;
		q.pop();
		if(p==b){
			cout << cnt << endl;
			return 0;
		}
		v[p.fst][p.snd]=true;
		ll i = p.fst+1;
		ll j = p.snd+1;
		while(i<n && j<n && s[i][j]=='.'){
			if(!v[i][j]){
				q.push(pair<pll,ll>(pll(i,j),cnt+1));
			}
			i++;j++;
		}

		i = p.fst+1;
		j = p.snd-1;
		while(i<n && j>=0 && s[i][j]=='.'){
			if(!v[i][j]){
				q.push(pair<pll,ll>(pll(i,j),cnt+1));
			}
			i++;j--;
		}

		i = p.fst-1;
		j = p.snd+1;
		while(i>=0 && j<n && s[i][j]=='.'){
			if(!v[i][j]){
				q.push(pair<pll,ll>(pll(i,j),cnt+1));
			}
			i--;j++;
		}

		i = p.fst-1;
		j = p.snd-1;
		while(i>=0 && j>=0 && s[i][j]=='.'){
			if(!v[i][j]){
				q.push(pair<pll,ll>(pll(i,j),cnt+1));
			}
			i--;j--;
		}
	}
	cout << -1 << endl;
}
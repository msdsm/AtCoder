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

using P = pair<ll, vector<ll> > ;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	queue<P> q;
	rep(i,m){
		vector<ll> tmp;
		tmp.push_back(i+1);
		q.push(P(1,tmp));
	}
	while(!q.empty()){
		P node = q.front();
		q.pop();
		ll d = node.fst;
		vector<ll> v = node.snd;
		if(d==n){
			rep(i,v.size()){
				cout << v[i] << ' ';
			}cout<<endl;
			continue;
		}
		for(ll i = v[v.size()-1]+1;i <= m; i++){
			vector<ll> tmp = v;
			tmp.push_back(i);
			q.push(P(d+1, tmp));
		}
	}
}
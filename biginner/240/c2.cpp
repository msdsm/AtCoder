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
	ll n,x;
	cin >> n >> x;
	vector<pll> p(n);
	pcin(p,n);
	stack<pll> open;//sum,depth
	open.push(pll(0,0));
	while(!open.empty()){
		pll tmp = open.top();
		open.pop();
		if(tmp.snd==n){
			if(tmp.fst==x){
				cout << "Yes" << endl;
				return 0;
			}
		}else{
			if(tmp.fst+p[tmp.snd].fst<=x)
				open.push(pll(tmp.fst+p[tmp.snd].fst,tmp.snd+1));
			if(tmp.fst+p[tmp.snd].snd<=x)
				open.push(pll(tmp.fst+p[tmp.snd].snd,tmp.snd+1));
		}
	}
	cout << "No" << endl;
}
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

using P = pair<pll,ll>;//level,color(0,1), multiply

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,x,y;
	cin >> n >> x >> y;
	ll cnt = 0;
	queue<P> q;//level,color 0:red
	q.push(P(pll(n,0),1));
	while(!q.empty()){
		P tt = q.front();
		pll tmp = tt.fst;
		ll mul = tt.snd;
		q.pop();
		if(tmp.fst == 1){
			if(tmp.snd==1){
				cnt += mul;
			}
			continue;
		}
		if(tmp.snd==0){
			q.push(P(pll(tmp.fst-1,0),mul));
			q.push(P(pll(tmp.fst,1),mul*x));
		}else{
			q.push(P(pll(tmp.fst-1,0),mul));
			q.push(P(pll(tmp.fst-1,1),mul*y));
		}
	}
	cout << cnt << endl;
}
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
	ll q;
	cin >> q;
	queue<pll> v;
	pll r = pll(0,0);
	while(q--){
		int a;
		cin >> a;
		if(a==1){
			ll x,c;
			cin >> x >> c;
			v.push(pll(x,c));
		}else{
			ll c;
			cin >> c;
			ll sum = 0;
			if(c<=r.snd){
				r.snd -= c;
				sum += r.fst*c;
			}else{
				sum += r.fst*r.snd;
				c -= r.snd;
				r.fst=0;
				r.snd=0;
				while(c){
					pll tmp = v.front();
					v.pop();
					if(c<=tmp.snd){
						sum += tmp.fst*c;
						r.fst = tmp.fst;
						r.snd = tmp.snd-c;
						c=0;
					}else{
						sum += tmp.fst*tmp.snd;
						c -= tmp.snd;
					}
				}
			}
			cout << sum << endl;
		}
	}
}
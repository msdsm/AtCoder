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
ll cnt;
using namespace std;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll h1,h2,h3,w1,w2,w3;
	cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
	if(h1+h2+h3!=w1+w2+w3){
		cout << 0 << endl;
		return 0;
	}
	rep2(1,a,30){
		rep2(1,b,30){
			rep2(1,c,30){
				rep2(1,d,30){
					if(h1-a-b<1)continue;
					if(h2-c-d<1)continue;
					if(w1-a-c<1)continue;
					if(w2-b-d<1)continue;
					if(h3-w1-w2+a+b+c+d<1)continue;
					cnt++;
				}
			}
		}
	}
	cout << cnt << endl;
}
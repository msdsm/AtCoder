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
	ll a,b,c,d,t;
	ll x = -1;
	ll y;
	ll l = 1;
	ll r = n;
	a=1;b=n;c=1;d=n;
	rep(i,30){
		if(x==-1){
			if(r==l+1){
				cout <<'?'<<' '<<l<<' '<<l<<' '<<c<<' '<<d<<endl;
				cin>>t;
				if(t==0)
					x = l;
				else
					x = r;
				l = 1;
				r = n;
				continue;
			}
			if(r==l){
				x = l;
				l = 1;
				r = n;
				continue;
			}
			c=1;
			d=n;
			a = l;
			b = (l+r)/2;
			cout <<'?'<<' '<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
			cin >> t;
			if(t==b-a+1){
				l = b+1;
			}else{
				r = b;
			}
		}else{//行特定
			if(r==l+1){
				cout <<'?'<<' '<<1<<' '<<n<<' '<<l<<' '<<l<<endl;
				cin>>t;
				if(t==0)
					y = l;
				else
					y = r;
				break;
			}
			if(l==r){
				y = l;
				break;
			}
			a = 1;
			b = n;
			c = l;
			d = (r+l)/2;
			cout <<'?'<<' '<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
			cin >> t;
			if(t==d-c+1){
				l = d+1;
			}else{
				r = d;
			}
		}
	}
	cout <<'!'<<' '<<x<<' '<<y<< endl;
	return 0;
}
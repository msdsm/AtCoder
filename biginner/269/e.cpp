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
	ll cnt = n-1;//[l,r]の個数
	rep(i,20){
		if(x==-1){
			c=1;
			d=n;
			a = l;
			b = (l+r)/2;
			cout <<'?'<<' '<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
			cin >> t;
			if(t==0){
				x = l;
				l = 1;
				r = n;
				cnt = n-1;
			}else if(t==1 && r==l+1){
				x = r;
				l = 1;
				r = n;
			}else if(t>static_cast<ld>(cnt)/2){
				l = b+1;
				cnt = cnt-t;
			}else{
				r = b;
				cnt = t;
			}
		}else{//行特定
			a = 1;
			b = n;
			c = l;
			d = (r+l)/2;
			cout <<'?'<<' '<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
			cin >> t;
			if(t==0){
				y = l;
				break;
			}else if(t==1 && r==l+1){
				y = r;
				break;
			}else if(t>static_cast<ld>(cnt)/2){
				l = d+1;
				cnt = cnt-t;
			}else{
				r = d;
				cnt = t;
			}
		}
	}
	cout <<'!'<<' '<<x<<' '<<y<< endl;
	return 0;
}
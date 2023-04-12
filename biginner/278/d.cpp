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
	cinf(a,n);
	ll q;
	cin >> q;
	ll start = 0;
	ll cnt=0;
	vector<ll> res(n);
	while(q--){
		ll t;
		cin >> t;
		if(t==1){
			ll x;
			cin >> x;
			start = x;
			cnt++;
		}else if(t==2){
			ll i,x;
			cin >> i >> x;
			i--;
			if(res[i]<cnt){
				res[i]=cnt;
				a[i]=start;
			}
			a[i]+=x;
		}else{
			ll i;
			cin >> i;
			i--;
			if(res[i]<cnt){
				a[i]=start;
				res[i]=cnt;
			}
			cout << a[i] << endl;
		}
	}
}
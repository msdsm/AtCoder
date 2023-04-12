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
	ll x,y;
	ll a,b,c,d;
	ll t;
	ll left = 0;
	ll right = n+1;
	c=1;
	d=n;
	ll cnt = n-1;
	while(right - left > 1){
		ll mid = left + (right - left)/2;
		a=left;
		b=mid;
		cout << '?'<<' '<<a+1<<' '<<b+1<<' '<<c<<' '<<d << endl;
		cin>>t;
		if(t<cnt/2){
			right = mid;
			cnt = t;
		}
		else{
			left = mid;
			cnt = cnt - t;
		}
	}
	x = right;
	left = 0;
	right = n+1;
	a=1;
	b=n;
	cnt = n-1;
	while(right - left > 1){
		ll mid = left + (right - left)/2;
		c=left;
		d=mid;
		cout << '?'<<' '<<a<<' '<<b<<' '<<c+1<<' '<<d+1<< endl;
		cin>>t;
		if(t<cnt/2){
			right = mid;
			cnt = t;
		}
		else{
			left = mid;
			cnt = cnt - t;
		}
	}
	y = right;
	cout << '!'<<' '<<x<<' '<<y << endl;
}
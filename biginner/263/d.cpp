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
	ll n,l,r;
	cin >> n >> l >> r;
	vector<ll> a(n);
	cinf(a,n);
	vector<ll> s(n);
	s[0]=a[0];
	rep2(1,i,n){
		s[i] = s[i-1]+a[i];
	}
/*
	cout << "debug start" << endl;
	rep(i,n)cout << s[i] << ' ';
	cout<<endl;
	cout << "debug end" << endl;
*/	
	
	ll x = 0;
	ll tmp = l;
	ll mi = 0;
	
	rep(i,n){
		if(mi<=s[i]-tmp){
			mi = s[i]-tmp;
			x = i+1;
		}
		tmp += l;
	}

	cout << "debug start s1" << endl;
	rep(i,n)cout<<s[i]<<' ';
	cout<<endl;
	cout << "debug end" << endl;
	
	
/*
	cout << "debug start" << endl;
	cout << x << endl;
	cout << "debug end" << endl;
*/	
	
	rep(i,x){
		a[i]=l;
	}
	s[0]=a[n-1];
	rep2(1,i,n){
		s[i] = s[i-1] + a[n-i-1];
	}
	ll y = 0;
	mi = 0;
	tmp = r;
	rep(i,n){
		if(mi<s[i]-tmp){
			mi = s[i]-tmp;
			y = i+1;
		}
		tmp += r;
	}
	rep(i,y){
		a[n-i-1]=r;
	}

	cout << "debug start" << endl;
	cout << x << endl;
	cout << y << endl;
	cout << "debug end" << endl;
	
	
	ll ans = 0;
	rep(i,n)ans+=a[i];
	cout << ans << endl;
}
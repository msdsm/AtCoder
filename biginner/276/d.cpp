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

ll gcd(ll a, ll b){
	if(a%b == 0){
		return b;
	}else{
		return gcd(b, a%b);
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	vector<ll> a(n);
	cinf(a,n);
	vector<ll> b(n);
	rep(i,n)b[i]=a[i];
	rep(i,n){
		ll tmp = b[i];
		bool flag1=false;
		bool flag2=false;
		if(tmp%2==0)
			flag1 = true;
		if(tmp%3==0)
			flag2 = true;
		while(flag1 || flag2){
			if(flag1)
				tmp/=2;
			if(flag2)
				tmp/=3;
			if(tmp%2==0)
				flag1 = true;
			else
				flag1 = false;
			if(tmp%3==0)
				flag2 = true;
			else
				flag2 = false;

			b[i] = tmp;
		}
	}
/*
	cout << "debug start b" << endl;
	rep(i,n)cout<< b[i] << ' ';
	cout<<endl;
	cout << "debug end" << endl;
*/	
	ll tmp = b[0];
	rep(i,n){
		if(b[i]!=tmp){
			cout << -1 << endl;
			return 0;
		}
	}
	ll g = a[0];
	rep(i,n){
		g = gcd(g,a[i]);
	}
	ll ans = 0;
	//cout << g << endl;
	rep(i,n){
		a[i]/=g;
	}
	rep(i,n){
		while(a[i]!=1){
			if(a[i]%2==0){
				ans++;
				a[i]/=2;
			}
			if(a[i]%3==0){
				ans++;
				a[i]/=3;
			}
		}
	}
	cout << ans << endl;
}
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
	vector<ll> a(n),b(n);
	rep(i,n)cin>>a[i]>>b[i];
	ll s=0;
	rep(i,n)s+=a[i];
	if(s==x){
		cout << "Yes" << endl;
		return 0;
	}
	if(s>x){
		cout << "No" << endl;
		return 0;
	}
	s=0;
	rep(i,n)s+=b[i];
	if(s==x){
		cout << "Yes" << endl;
		return 0;
	}
	if(s<x){
		cout << "No" << endl;
		return 0;
	}
	for(ll bits=0; bits<(1<<n); bits++){
		ll sum = 0;
		rep(i,n){
			if(bits&(1<<i)){
				sum+=a[i];
			}else{
				sum+=b[i];
			}
			if(sum>x)
				break;
			if(i==n-1&&sum==x){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}
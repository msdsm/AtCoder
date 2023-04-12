//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll f(ll x){
	vector<ll> a;
	while(x>0){
		a.push_back(x%10);
		x/=10;
	}
	sort(a.begin(),a.end());
	ll g1 = 0;
	ll g2 = 0;
	rep(i,a.size()){
		g1*=10;
		g2*=10;
		g1+=a[a.size()-i-1];
		g2+=a[i];
	}
	return g1-g2;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll n,k;
	cin >> n >> k;
	ll tmp = n;
	rep(i,k){
		tmp = f(tmp);
	}
	cout << tmp << endl;	
}
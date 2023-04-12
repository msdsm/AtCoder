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

ll sum;
ll ans;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll n;
	cin >> n;
	vector<ll> a(n),b(n),s(n);
	cinf(a,n);
	sort(a.begin(),a.end());
	rep(i,n){
		sum+=a[i];
	}
/*
cout <<  "debug start" << endl;
coutf(a,n);
cout << "debug end" << endl;
*/
	s[0]=sum;
	arep(1,i,n){
		s[i]=s[i-1]-a[i-1];
	}
/*
cout <<  "debug start" << endl;
coutf(s,n);
cout << "debug end" << endl;
*/
	rep(i,n-1){
		b[i]=s[i+1]-(n-i-1)*a[i];
	}
/*
cout <<  "debug start" << endl;
coutf(b,n);
cout << "debug end" << endl;
*/
	rep(i,n-1){
		ans+=b[i];
	}
	cout << ans << endl;
}
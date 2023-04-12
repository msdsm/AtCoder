//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ull cnt;

template <class Type>
Type digit(Type n){
  if(n==0)
    return 1;
  return 1+floor(log10(n));
}

ll count(ll x){
	if(x==0)
		return 0;
	ll c = 0;
	while(x){
		x/=1000;
		c++;
	}
	return c-1;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	ll m = n;
	//cout << count(n) << endl;
	cnt+=count(n)*(n-powl(10,count(n)*3)+1);
	ll c = count(n);
	if(c==0){
		cout << 0 << endl;
		return 0;
	}
	while(--c){
		cnt+=c*(powl(10,c*3+3)-1-powl(10,c*3)+1);
	}
	cout << cnt << endl;
}
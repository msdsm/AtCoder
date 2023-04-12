#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll x[100001];
ll cnt;

int main(){
	ll n,a,b;
	cin >> n >> a >> b;
	cinf(x,n);
	rep(i,n-1){
		cnt+=(((x[i+1]-x[i])*a>b)?b:(x[i+1]-x[i])*a);
	}
	cout << cnt << endl;
}
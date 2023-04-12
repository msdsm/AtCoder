#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll cnt;

int main(){
	ll n,d;
	cin >> n >> d;
	ll x[n];
	ll y[n];
	rep(i,n){
		cin >> x[i] >> y[i];
	}
	rep(i,n){
		if(d*d>=x[i]*x[i]+y[i]*y[i])
			cnt++;
	}
	cout << cnt << endl;
}
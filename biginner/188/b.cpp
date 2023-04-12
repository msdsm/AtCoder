#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
	ll n;
	cin >> n;
	ll a[n],b[n];
	cinf(a,n);
	cinf(b,n);
	ll sum = 0;
	rep(i,n){
		sum+= a[i]*b[i];
	}
	if(sum==0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
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
	ll a[n];
	cinf(a,n);
	if(n==1){
		cout << a[0] << endl;
		return 0;
	}
	else if(n%2==0){
		for(ll i=n-1;i>=0;i-=2){
			cout << a[i] << ' ';
		}
		for(ll i=0;i<n-2;i+=2){
			cout << a[i] << ' ';
		}
	}else{
		for(ll i=n-1;i>=0;i-=2){
			cout << a[i] << ' ';
		}
		for(ll i=1;i<n-2;i+=2){
			cout << a[i] << ' ';
		}
	}
	cout << a[n-2] << endl;
}
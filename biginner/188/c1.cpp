#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll max1,max2;
ll m1,m2;

int main(){
	ll n;
	cin >> n;
	vector<ll> a(1<<n);
	cinf(a,1<<n);
	rep(i,(1<<n)/2){
		if(max1<a[i]){
			max1=a[i];
			m1=i;
		}
	}
	arep((1<<n)/2,i,1<<n){
		if(max2<a[i]){
			max2=a[i];
			m2=i;
		}
	}
	if(max1<max2)
		cout << m1+1 << endl;
	else
		cout << m2+1 << endl;
}
#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll a[10000001];

int main(){
	ll n;
	cin >> n;
	ull sum=0;
	for(ll i=1;i<n+1;i++){
		for(ll j=i;j<n+1;j+=i){
			a[j]++;
		}
	}
	arep(1,i,n+1){
		sum+=i*a[i];
	}
	cout << sum << endl;
}
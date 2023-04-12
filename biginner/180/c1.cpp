#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll a[1000010];
ll b[1000010];

int main(){
	ll n;
	cin >> n;
	ll j=0,k=0;
	arep(1,i,sqrt(n)){
		if(n%i==0){
			if(i==n/i){
				a[j]=i;
				j++;
				break;
			}
			a[j]=i;
			b[k]=n/i;
			j++;
			k++;
		}
	}
	rep(i,j){
		cout << a[i] << endl;
	}
	/*if(sqrt(n)==static_cast<ll>(sqrt(n)))
		cout << sqrt(n) << endl;*/
	rep(i,k){
		cout << b[k-i-1] << endl;
	}
}
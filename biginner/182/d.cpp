#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll ans;
ll sum;

int main(){
	ll n;
	cin >> n;
	ll a[n];
	cinf(a,n);
	rep(i,n){
		rep(j,i+1){
			sum+=a[j];
//cout << sum << endl;
			if(ans<sum)
				ans=sum;
		}
	}
	cout << ans << endl;
}
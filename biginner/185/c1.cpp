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

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ld l;
	ld ans=1;
	cin >> l;
	rep(i,11){
		ans*=(l+i-11);
		ans/=(i+1);

		/*cout << "debug start" << endl;
		cout << ans << endl;
		cout << "debug end" << endl;*/
		
		
	}
	cout << static_cast<ll>(ans) << endl;
}
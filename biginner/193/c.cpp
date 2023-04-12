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
	ll n;
	cin >> n;
	ll tmp;
	set<ll> st;
	if(n==1){
		cout << n << endl;
		return 0;
	}
	for(ll i = 2; i*i<=n;i++){
		tmp = i;
		for(ll j = 2; tmp*i<=n;j++){
			tmp*=i;
			st.insert(tmp);
		}
	}
	cout << n-st.size() << endl;
}
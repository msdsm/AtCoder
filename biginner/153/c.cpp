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

ll sum;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll n,k;
	cin >> n >> k;
	vector<ll> h(n);
	cinf(h,n);
	sort(h.begin(),h.end());
	if(k>=n)
		cout << 0 << endl;
	else{
		vector<ll> j(n-k);
		rep(i,n-k){
			j[i]=h[i];
		}
		rep(i,n-k){
			sum+=j[i];
		}
		cout << sum << endl;
	}
	//cout << sum << endl;
}
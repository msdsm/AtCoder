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
	ll h,n;
	cin >> h >> n;
	vector<ll> a(n);
	cinf(a,n);
	rep(i,n){
		sum+=a[i];
	}
	if(sum<h)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}
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
	ll n,k;
	cin >> n >> k;
	vector<ll> p(n);
	cinf(p,n);
	ll max=0;
	ll sum=0;
	rep(i,k){
		sum+=p[i];
	}
	max=sum;
	arep(k,i,n){
		sum+=p[i];
		sum-=p[i-k];
		if(sum>max)
			max=sum;
	}

/*
	cout << "debug start" << endl;
	cout << max << endl;
	cout << "debug end" << endl;
*/
	
	cout << setprecision(10) << static_cast<ld>(max+k)/2 << endl;
}
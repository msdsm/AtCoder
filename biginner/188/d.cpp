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

ull ans;
ll sum[1000000000];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll n,C;
	cin >> n >> C;
	vector<ll> a(n),b(n),c(n);

	rep(i,n){
		cin >> a[i] >> b[i] >> c[i];
		sum[a[i]-1]+=c[i];
		sum[b[i]]+=-c[i];
	}
	ll min=a[0];
	ll max=b[0];
	rep(i,n){
		if(min>a[i])min=a[i];
		if(max<b[i])max=b[i];
	}
	arep(min,i,max){
		sum[i]+=sum[i-1];
	}

	/*cout << "debug start" << endl;
	cout << min << endl;
	cout << max << endl;
	arep(min-1,i,max){
		cout << sum[i] << endl;
	}
	cout << "debug end" << endl;*/
	
	
	arep(min-1,i,max){
		if(sum[i]<C)
			ans+=sum[i];
		else
			ans+=C;
	}
	cout << ans << endl;
}
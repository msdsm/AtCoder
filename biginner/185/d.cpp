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

ll ans;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll n,m;
	cin >> n >> m;
	if(m==0){cout << 1 << endl;return 0;}
	vector<ll> a(m);
	cinf(a,m);
	sort(a.begin(),a.end());
	vector<ll> b(m+1);
	b[0]=a[0]-1;
	arep(1,i,m){
		b[i]=a[i]-a[i-1]-1;
	}
	b[m]=n-a[m-1];
	ll min = n;

	//cout << "debug start" << endl;
	//coutf(b,m+1);
	//cout << "debug end" << endl;
	
	
	rep(i,m+1){
		if(min>b[i]&&b[i]!=0)
			min = b[i];
	}

	//cout << "debug start" << endl;
	//cout << min << endl;
	//cout << "debug end" << endl;
	
	
	rep(i,m+1){
		ans+= b[i]/min;
		if(b[i]%min!=0)ans++;
	}
	cout << ans << endl;
}
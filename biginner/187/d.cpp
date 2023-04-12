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
ll cnt;

int main(){
	ll n;
	cin >> n;
	vector<ll> a(n),b(n),c(n);
	rep(i,n){
		cin >> a[i] >> b[i];
	}
	rep(i,n){
		sum-=a[i];
	}
	rep(i,n){
		c[i] = 2*a[i]+b[i];
	}

//coutf(c,n);

	sort(c.begin(),c.end());

//coutf(c,n);

	while(sum<=0){
		auto itr = c.end()-1;

//cout << *itr << endl;

		sum+=*itr;
		cnt++;
		c.pop_back();
	}
	cout << cnt << endl;
}
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll sum;
ll cnt;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll r,x,y;
	cin >> r >> x >> y;
	ll d = x*x+y*y;
	while(sum<d){
		cnt++;
		sum=r*r*cnt*cnt;
	}
	if(cnt==1){
		if(sum==d)
			cout << 1 << endl;
		else
			cout << 2 << endl;
	}else{
		cout << cnt << endl;
	}
}
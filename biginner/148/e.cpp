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

ull ans;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ull n;
	cin >> n;
	if(n%2==1){
		cout << 0 << endl;
	}else{
		ll tmp = 5;
		while(n>=tmp){
			ans+=n/(2*tmp);
			tmp*=5;
		}
		cout << ans << endl;
	}
}
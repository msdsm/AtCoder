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

ll cnt;

/*整数の桁数をO(1)で計算*/
template <class Type>
Type digit(Type n){
  if(n==0)
    return 1;
  return 1+floor(log10(n));
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	int d = digit(n);
	for(ll i = 1;i*i<=n;i++){
		ll tmp = i*powl(10,digit(i))+i;
		if(tmp<=n)
			cnt++;
		else
			break;
	}
	cout << cnt << endl;
}
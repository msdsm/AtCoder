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

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	vector<ll> a(n);
	cinf(a,n);
	ll j = 1;
	rep(i,n){
		if(a[i]==j){
			j++;
		}else{
			a[i]=-1;
		}
	}
	rep(i,n){
		if(a[i]==-1)
			cnt++;
	}

	if(cnt==n)
		cout << -1 << endl;
	else
		cout << cnt << endl;
}
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

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	int n,k,m;
	cin >> n >> k >> m;
	vector<int> a(n-1);
	cinf(a,n-1);
	rep(i,n-1)sum+=a[i];
	if(n*m-sum>k)
		cout << -1 << endl;
	else if(n*m-sum<0)
		cout << 0 << endl;
	else
		cout << n*m-sum << endl;
}
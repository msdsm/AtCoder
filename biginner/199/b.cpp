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

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	cinf(a,n);
	cinf(b,n);
	int min = a[0];
	int max = b[0];
	rep2(1,i,n){
		if(min<a[i])
			min=a[i];
		if(max>b[i])
			max=b[i];
	}
	if(max<min)
		cout << 0 << endl;
	else
		cout << max-min+1 << endl;
}
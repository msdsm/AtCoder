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

ll sum;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	int h,w;
	cin >> h >> w;
	ll a[h][w];
	rep(i,h)rep(j,w)cin >> a[i][j];
	ll min = a[0][0];
	rep(i,h)rep(j,w){
		if(min>a[i][j])
			min=a[i][j];
	}
	rep(i,h)rep(j,w){
		sum += (a[i][j]-min);
	}
	cout << sum << endl;
}
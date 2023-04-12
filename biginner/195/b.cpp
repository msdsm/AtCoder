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

bool flag;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	int a,b,w;
	cin >> a >> b >> w;
	w*=1000;
	ll min=w+1;
	ll max = -1;
	rep2(1,i,w+1){
		if((ld)w/i<=b && (ld)w/i>=a){
			if(min>i)
				min=i;
			if(max<i)
				max=i;
		}
	}
	if(max!=-1&&min!=w+1)
		cout << min << ' ' << max << endl;
	else
		cout << "UNSATISFIABLE" << endl;
}
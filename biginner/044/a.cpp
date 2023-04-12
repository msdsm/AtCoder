#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll ans;

int main(){
	ll n,k,x,y;
	cin >> n;
	cin >> k;
	cin >> x;
	cin >> y;
	rep(i,n){
		if(i<k)
			ans+=x;
		else
			ans+=y;
	}
	cout << ans << endl;
}
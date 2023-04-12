#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int a[8];
int cnt;
int sum;

int main(){
	ll n;
	cin >> n;
	int tmp;
	rep(i,n){
		cin >> tmp;
		if(tmp<3200)
			a[tmp/400]=1;
		else
			cnt++;
	}
	rep(i,8)sum+=a[i];
	if(sum>=1)
		cout << sum << ' ' << sum+cnt << endl;
	else
		cout << 1 << ' ' << cnt << endl;
}
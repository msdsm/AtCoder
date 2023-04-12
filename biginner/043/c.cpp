#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll a[101];
ll sum;
ll ans;
ll ave;

int main(){
	ll n;
	cin >> n;
	rep(i,n){
		cin >> a[i];
		sum+=a[i];
	}
	double avetmp = static_cast<double>(sum)/n;
	if(abs(avetmp-static_cast<ll>(avetmp)<0.5))
		ave = static_cast<ll>(avetmp);
	else
		ave = static_cast<ll>(avetmp)+1;
	rep(i,n){
		ans+=(a[i]-ave)*(a[i]-ave);
	}
	cout << ans << endl;
}
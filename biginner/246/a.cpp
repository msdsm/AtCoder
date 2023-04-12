//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
#define fst first
#define snd second
#define pcin(x,n) for(ll i=0;i<(n);i++)cin>>x[i].fst>>x[i].snd;
#define pdebug(x) cout << '(' << x.fst << ',' << x.snd << ")\n";
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	int x[3];
	int y[3];
	rep(i,3)cin>>x[i]>>y[i];
	int ans1,ans2;
	if(x[0]==x[1])
		ans1=x[2];
	else if(x[1]==x[2])
		ans1=x[0];
	else
		ans1=x[1];
	if(y[0]==y[1])
		ans2=y[2];
	else if(y[1]==y[2])
		ans2=y[0];
	else
		ans2=y[1];
	cout << ans1 <<  ' ' << ans2 << endl;
}
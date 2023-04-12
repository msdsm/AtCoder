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
	ll x,y,z;
	cin >> x >> y >> z;
	if((0<y&&y<x&&x<z) || (0<y&&y<z&&z<x))
		cout << -1 << endl;
	else if((z<x&&x<y&&y<0) || (x<z&&z<y&&y<0))
		cout << -1 << endl;
	else{
		if((0<y&&y<x) || (x<y&&y<0)){
			cout << abs(z)+abs(x-z) << endl;
		}else{
			cout << abs(x) << endl;
		}
	}
}
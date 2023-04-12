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
	ll v,a,b,c;
	cin >> v >> a >> b >> c;
	while(v){
		v -= a;
		if(v<0){
			cout << "F" << endl;
			return 0;
		}
		if(v==0){
			cout << "M" << endl;
			return 0;
		}
		v -= b;
		if(v<0){
			cout << "M" << endl;
			return 0;
		}
		if(v==0){
			cout << "T" << endl;
			return 0;
		}
		v -= c;
		if(v<0){
			cout << "T" << endl;
			return 0;
		}
		if(v==0){
			cout << "F" << endl;
			return 0;
		}
	}
}
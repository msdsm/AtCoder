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
	ll n,m;
	cin >> n >> m;
	if(static_cast<ld>(n) < static_cast<ld>(m)/n){
		cout << -1 << endl;
		return 0;
	}
/*	
	if(m%n==0 && n<m/n){
		cout << -1 << endl;
		return 0;
	}
	if(m%n!=0 && n<=m/n){
		cout << -1 << endl;
		return 0;
	}
*/	
	ll ans = numeric_limits<ll>::max();
	ll tmp,b;
	for(ll a = 1; a*a <= 10*m; a++){
		if(m%a==0){
			b = m/a;
			tmp = a*b;
		}else{
			b = m/a+1;
			tmp = a*b;
		}
		if(a>n || b>n)
			continue;
/*		cout << "debug start" << endl;
		cout << a << endl;
		cout << b << endl;
		cout << tmp << endl;
		cout << "debug end" << endl;
*/		
		
		if(tmp<ans){
			ans=tmp;
		}
	}
	cout << ans << endl;
}
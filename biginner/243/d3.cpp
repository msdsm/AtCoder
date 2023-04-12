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
/*
ll poww(ll x,ll n){
	if(n==0)return 1;
	ll val = poww(x,n/2);
	val *= val;
	if(n%2==1)val*=x;
	return val;
}
*/

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,x;
	cin >> n >> x;
	string s;
	cin >> s;
	ll y = x;
	ll cntu=0;
	ll cntl=0;
	rep(i,n){
		ll tmp = y;
		if(cntl-cntu>0){
			tmp *= powl(2,cntl-cntu);
		}else{
			tmp /= powl(2,cntu-cntl);
		}
		
		cout << "debug start" << endl;
		cout << i << ' ' << s[i] << endl;
		cout << tmp << endl;
		cout << x << endl;
		cout << "debug end" << endl;
		
		
		/*
		if(x!=tmp){
			
			cout << "debug start" << endl;
			cout << x << endl;
			cout << tmp << endl;
			cout << i << endl;
			cout << "debug end" << endl;
			
			
		}*/
		if(s[i]=='U'){
			x = x/2;
			cntu++;
		}
		else if(s[i]=='R'){
			x = 2*x+1;
			if(cntl-cntu>0){
				y *= powl(2,cntl-cntu);
			}else{
				rep(j,cntu-cntl){
					if(y%2==1)
						y--;
					y/=2;
				}
			}
			y = 2*y+1;
			cntl=0;
			cntu=0;
		}
		else{
			x = 2*x;
			cntl++;
		}
	}
	if(cntl-cntu>0){
		y *= powl(2,cntl-cntu);
	}else{
		y /= powl(2,cntu-cntl);
	}
	cout << x << endl;
	cout << y << endl;
}
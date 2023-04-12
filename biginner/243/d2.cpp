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

ll poww(ll x,ll n){
	if(n==0)return 1;
	ll val = poww(x,n/2);
	val *= val;
	if(n%2==1)val*=x;
	return val;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,x;
	cin >> n >> x;
	string s;
	cin >> s;
	ll cntu=0;
	ll cntl=0;
	rep(i,n){
		if(s[i]=='U'){
			cntu++;
		}
		else if(s[i]=='L'){
			cntl++;
		}
		else{
			if(cntl-cntu>0){
				x *= poww(2,cntl-cntu);
			}else{
				x /= poww(2,cntu-cntl);
			}
			x = 2*x+1;
			cntl=0;
			cntu=0;
		}
	}
	if(cntl-cntu>0){
				x *= poww(2,cntl-cntu);
			}else{
				x /= poww(2,cntu-cntl);
			}
	cout << x << endl;
}
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

bool f(ll x,ll l,ll r){
	if(x<=r && x>=l)
		return true;
	return false;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,a,b;
	cin >> n >> a >> b;
	ll p,q,r,s;
	cin >> p >> q >> r >> s;
	ll le = max(1-a,1-b);
	ll ri = min(n-a,n-b);
	ll le2 = max(1-a,b-n);
	ll ri2 = min(n-a,b-1);
	//cout << p << endl;
	//cout << q-p+1 << endl;
	rep2(p,i,q+1){
		//cout << i << endl;
		rep2(r,j,s+1){
			//if((max(1-a,1-b)+a<=i && i<=min(n-a,n-b)+a && max(1-a,1-b)+b<=j && j<=min(n-a,n-b)+b)||
			//	(max(1-a,b-n)+a<=i && i<=min(n-a,b-1)+a && b-max(1-a,b-n)>=j && b-min(n-a,b-1)<=j))
		/*	cout << i << ' ' << j << endl;
			cout << a+le << ' ' << a+ri << endl;
			cout << b+le << ' ' << b+ri << endl;
			cout << a+le2 << ' ' << a+ri2 << endl;
			cout << b-ri2 << ' ' << b-le2 << endl;
			*/
			if((f(i,a+le,a+ri)&&j==b+i-a)||(f(i,a+le2,a+ri2)&&j==b-i+a)){
				cout << '#';
			}
			else{
				cout << '.';
			}
		}
		cout << endl;
	}
}
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

ull f(ull x, ull a, ull b, ull c){
	return ( (a&x) | (b&(~x)) | c) ;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ull n,C;
	cin >> n >> C;
	vector<int> t(n);
	vector<ull> A(n);
	rep(i,n){
		cin >> t[i] >> A[i];
	}
	ull a = numeric_limits<ull>::max();
	ull b = 0;
	ull c = 0;
	ull x = C;
	//cout << f(x,a,b,c) << endl;
	rep(i,n){
		if(t[i]==1){
			a = (a&A[i]);
			b = (b&A[i]);
			c = (c&A[i]);
		}else if(t[i]==2){
			c = ( c|A[i] );
		}else{
			ull tmpa = ((a&(~A[i]))|((~c)&A[i]&(~a)));
			ull tmpb = ( (b & (~A[i]) ) | ( (~c) & A[i] & (~b) ) );
			ull tmpc = ((c & (~A[i]) ) | ( (~c) & A[i] & (~a) & (~b) ));
			a = tmpa;
			b = tmpb;
			c = tmpc;
		}
		x = f(x,a,b,c);
		cout << x << endl;
	}
}
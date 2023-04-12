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

ull GCD(ull a,ull b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ull n,a,b;
	cin >> n >> a >> b;
	ull sum = n*(n+1)/2;
	//cout << sum << endl;
	ull sa=0;
	ull sb=0;
	ull sg=0;
	ull g = GCD(a,b);
	g = a/g*b;
	ull ma,mb,mg;
	ma = n/a;
	mb = n/b;
	mg = n/g;
	sa = ma*(ma+1)/2*a;
	sb = mb*(mb+1)/2*b;
	sg = mg*(mg+1)/2*g;
	/*
	cout << "debug start" << endl;
	cout << sum << endl;
	cout << sa << endl;
	cout << sb << endl;
	cout << sg << endl;
	cout << "debug end" << endl;
	
	*/
	cout << sum-sa-sb+sg << endl;
}
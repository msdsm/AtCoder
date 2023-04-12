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
	ll n,x;
	cin >> n >> x;
	vector<ll> a(n),b(n);
	rep(i,n)cin>>a[i]>>b[i];
	vector<ll> s(n);
	ll sum = 0;
	rep(i,min(n,x)){
		sum += a[i]+b[i];
		s[i] = sum;
		if(x-i-1>0)
			s[i] += b[i]*(x-i-1);
	}
	ll inf = numeric_limits<ll>::max();
	rep(i,n){
		if(s[i]==0)
			s[i]=inf;
	}
	cout << *min_element(s.begin(),s.end()) << endl;
}
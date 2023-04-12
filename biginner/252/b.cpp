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
	ll n,k;
	cin >> n >> k;
	vector<ll> a(n),b(k);
	cinf(a,n);
	cinf(b,k);
	set<ll> st;
	rep(i,k)st.insert(b[i]-1);
	vector<pll> p(n);
	rep(i,n){
		p[i].fst = a[i];
		p[i].snd = i;
	}
	sort(p.begin(),p.end(),greater<pll>());
	vector<ll> v;
	//cout << a[0] << endl;
	ll max = p[0].fst;
	rep(i,n){
		if(p[i].fst==max)
			v.push_back(p[i].snd);
	}
/*
	cout << "debug start max" << endl;
	cout << max << endl;
	cout << "debug end" << endl;

	cout << "debug start" << endl;
	rep(i,v.size())cout<<v[i]<<' ';
	cout << endl;
	cout << "debug end" << endl;
*/	
	
	
	
	rep(i,v.size()){
		if(st.count(v[i])>0){
			cout << "Yes" << endl;
			return 0;
		}
		else
			continue;
	}
	cout << "No" << endl;
}
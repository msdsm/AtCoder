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
	ll m,n;
	cin >> n >> m;
	vector<ll> a(n);
	vector<ll> b(m);
	cinf(a,n);
	cinf(b,m);
	set<ll> st;
	rep(i,n){
		st.insert(a[i]);
	}
	rep(i,m){
		if(st.count(b[i])>0){
			st.erase(b[i]);
		}else{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
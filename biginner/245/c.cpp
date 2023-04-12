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
	vector<ll> a(n),b(n);
	cinf(a,n);
	cinf(b,n);
	vector<ll> pre;
	pre.push_back(a[0]);
	pre.push_back(b[0]);
	rep2(1,i,n){
		vector<ll> tmp;
		if(pre.empty()){
			cout << "No" << endl;
			return 0;
		}

		cout << "debug start pre" << endl;
		cout << pre.size() << endl;
		cout << "debug end" << endl;
		
		
		rep(j,pre.size()){
			if(abs(a[i]-pre[j])<=k)
				tmp.push_back(a[i]);
			if(abs(b[i]-pre[j])<=k)
				tmp.push_back(b[i]);
		}
		pre = tmp;
	}
	if(pre.empty())
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}
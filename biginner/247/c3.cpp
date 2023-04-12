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

vector<ll> f(ll n){
	if(n==1){
		vector<ll> v;
		v.push_back(1);
		return v;
	}
	vector<ll> tmp = f(n-1);
	vector<ll> v = tmp;
	v.push_back(n);
	rep(i,tmp.size()){
		v.push_back(tmp[i]);
	}
	return v;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	vector<ll> ans = f(n);
	rep(i,ans.size()){
		if(i!=ans.size()-1)
			cout << ans[i] << ' ';
		else
			cout << ans[i] << endl;
	}
}
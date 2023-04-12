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
ll cnt1;
ll cnt2;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	vector<pll> p(m);
	pcin(p,m);
	if(n!=m+1){
		cout << "No" << endl;
		return 0;
	}
	vector<ll> deg(n);
	rep(i,m){
		p[i].fst--;
		p[i].snd--;
		deg[p[i].fst]++;
		deg[p[i].snd]++;
	}
	rep(i,n){
		if(deg[i]==1)
			cnt1++;
		if(deg[i]==2)
			cnt2++;
	}
	if(cnt1==2 && cnt2==n-2)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
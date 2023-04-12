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

ll ans;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	vector<ll> a(n);
	cinf(a,n);
	sort(a.begin(),a.end());
	vector<ll> cnt(a[n-1]+2);
	cnt[a[n-1]+1] = n;
	rep(i,n)cnt[a[i]]+=-1;
	rep2(1,i,cnt.size()){
		cnt[cnt.size()-1-i] += cnt[cnt.size()-1-i+1];
	}
	rep(i,n){
		ans += cnt[a[i]]*(n-cnt[a[i]+1]);
	}
/*
	cout << "debug start" << endl;
	rep(i,cnt.size())cout << cnt[i] << ' ';
	cout << endl;
	cout << "debug end" << endl;
*/	
	cout << ans << endl;
}
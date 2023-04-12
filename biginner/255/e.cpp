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
	ll n,m;
	cin >> n >> m;
	vector<ll> s(n-1);
	vector<ll> x(m);
	cinf(s,n-1);
	cinf(x,m);
	map<ll,ll> cnt;
	ll ans;
	rep(j,m){
		ll sum = 0;
		rep(i,n){
			ll a1 = 0;
			if(i==0){
				a1 = x[j];
			}else if(i%2==0){
				sum -= s[i-1];
				a1 = sum + x[j];
			}else{
				sum += s[i-1];
				a1 = sum - x[j];
			}
/*
			cout << "debug start" << endl;
			cout << i << ' ' << j << endl;
			cout << a1 << endl;
			cout << "debug end" << endl;
*/			
			
			cnt[a1]++;
			if(cnt[ans]<cnt[a1])
				ans=a1;
		}
	}
	cout << cnt[ans] << endl;
}
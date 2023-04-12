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
	ll n,w;
	cin >> n >> w;
	vector<pll> p(n);
	ll sum=0,ans=0;
	pcin(p,n);
	sort(p.begin(),p.end(),greater<pll>());
	//rep(i,n)cout << p[i].fst << ' ' << p[i].snd << endl;
	ll i = 0;
	while(sum<w&&i<n){
		ll tmp = min(p[i].snd,w-sum);
		sum+=tmp;
		ans+=p[i].fst*tmp;
		i++;
	}
	cout << ans << endl;
}
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
	vector<ll> cnt(n+1);
	cnt[0]=0;
	rep2(1,i,n+1){
		ll tmp1=0;
		ll tmp2=0;
		for(ll c=1;c*c<=i;c++){
			if(c*c==i){
				tmp2++;
			}
			else if(i%c==0){
				tmp1++;
			}
		}
		cnt[i] = 2*tmp1+tmp2;
	}
	rep2(1,a,n+1){
		rep2(1,b,n/a+1){
			ans += cnt[n-a*b];
		}
	}
	cout << ans << endl;
}
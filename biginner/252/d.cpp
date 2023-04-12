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
	ll n;
	cin >> n;
	vector<ll> a(n);
	cinf(a,n);
	sort(a.begin(),a.end());
	vector<pll> dp(n);
	dp[0].fst = 0;
	dp[0].snd = 0;
	dp[1].fst = (a[0]!=a[1]?1:0);
	dp[1].snd = 0;
	ll pre=0;
	ll cnt = 0;
	if(a[0]!=a[1])cnt++;
	rep2(2,i,n){
		if(a[i]!=a[i-1]){
			dp[i].fst = dp[i-1].fst + i;
			pre = i;
			cnt++;
		}
		else
			dp[i].fst = dp[i-1].fst + pre;

		if(cnt<2){
			dp[i].snd = 0;
		}else{
			if(a[i]!=a[i-1])
				dp[i].snd = dp[i-1].snd + dp[i-1].fst;
			else
				dp[i].snd = dp[i-1].snd + dp[pre-1].fst;
		}
	}


	cout << "debug start a" << endl;
	rep(i,n)cout << a[i] << ' ';
	cout << endl;
	cout << "debug end" << endl;
	
	
	cout << "debug start pair" << endl;
	rep(i,n)cout << dp[i].fst << ' ';
	cout << endl;
	cout << "debug end" << endl;
	cout << "debug start pair3" << endl;
	rep(i,n)cout << dp[i].snd << ' ';
	cout << endl;
	cout << "debug end" << endl;

	cout << dp[n-1].snd << endl;
}
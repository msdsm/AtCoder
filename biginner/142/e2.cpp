//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int inf = INT_MAX / 2;
const ll infl = 1LL << 60;
template<class T>bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T& a,const T& b){if(b<a){a=b;return 1;}return 0;}

using namespace std;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	int n,m;
	cin >> n >> m;
	vector<ll> a(m),b(m);
	vector<ll> f(m);
	rep(i,m){
		cin>>a[i]>>b[i];
		rep(j,b[i]){
			int c;
			cin>>c;
			c--;
			f[i] = f[i]|(1<<c);
		}
	}
/*
	cout << "debug start" << endl;
	rep(i,m){
		cout << a[i] << ' ' << b[i] << endl;
		cout << bitset<13>(f[i]) << endl;
	}
	cout << "debug end" << endl;
*/
	ll dp[m+1][(1<<n)];
	rep(i,m+1)rep(j,1<<n)dp[i][j]=infl;
	dp[0][0]=0;
	rep(i,m)rep(j,1<<n){
		chmin(dp[i+1][j|f[i]],dp[i][j]+a[i]);//iの鍵使用したときの遷移はf[i]だけ集合増える
		chmin(dp[i+1][j],dp[i][j]);//iの鍵使用しないときの遷移はそのままおりる
	}
/*
	cout << "debug start" << endl;
	rep(i,m+1)rep(j,1<<n){
		if(j==(1<<n)-1)
			cout << dp[i][j] << endl;
		else
			cout << dp[i][j] << ' ';
	}
	cout << "debug end" << endl;
*/	
	
	ll ans = dp[m][(1<<n)-1];//m-1番までの鍵の使用が決定していて、1<<n-1の集合の箱を開けられるコストの最小
	if(ans==infl)
		cout << -1 << endl;
	else
		cout << ans << endl;
}
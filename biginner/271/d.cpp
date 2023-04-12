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

using P = pair<bool, bool>;
pair<bool, bool> f = pair<bool, bool>(false, false);
//できるかどうか、できるならa(true)かb(false)か

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,s;
	cin >> n >> s;
	vector<ll> a(n),b(n);
	rep(i,n)cin>>a[i]>>b[i];
	vector<vector<P> >  dp(n);
	rep(i,n)dp[i].resize(10000+1,f);
	dp[0][a[0]]=P(true,true);
	dp[0][b[0]]=P(true,false);
	rep2(1,i,n){
		rep(j,10000+1){
			if(dp[i-1][j].fst){
				dp[i][j+a[i]] = P(true,true);
				dp[i][j+b[i]] = P(true,false);
			}
		}
	}
	if(dp[n-1][s].fst){
		cout << "Yes" << endl;
		string ans;
		ll next = s;
		rep(i,n){
			if(dp[n-i-1][next].snd){
				ans.push_back('H');
				next -= a[n-i-1];
			}else{
				ans.push_back('T');
				next -= b[n-i-1];
			}
		}
		reverse(ans.begin(),ans.end());
		cout << ans << endl;
	}else{
		cout << "No" << endl;
	}
}
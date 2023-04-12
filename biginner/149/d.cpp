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

static int R = 0;
static int S = 1;
static int P = 2;
static int N = 3;

ll ans;

int f(char c,int x){
	switch(c){
		case 'r':
		if(x==P)
			return P;
		else
			return N;
		break;

		case 's':
		if(x==R)
			return R;
		else
			return N;
		break;
		case 'p':
		if(x==S)
			return S;
		else
			return N;
		break;
	}
	return N;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,k;
	cin >> n >> k;
	ll value[4];//r,s,p,なし
	cinf(value,3);//r,s,p
	value[N]=0;
	string t;
	cin >> t;
	vector<string> v(k);
	rep(i,n){
		v[i%k].push_back(t[i]);
	}
/*
	cout << "debug start" << endl;
	rep(i,k){
		rep(j,v[i].size()){
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;
*/	
	rep(i,k){
		ll dp[v[i].size()][3];
		dp[0][R]=value[f(t[i],R)];
		dp[0][S]=value[f(t[i],S)];
		dp[0][P]=value[f(t[i],P)];
		rep2(1,j,v[i].size()){
			dp[j][R]=max(dp[j-1][S]+value[f(t[i+j*k],R)],dp[j-1][P]+value[f(t[i+j*k],R)]);
			dp[j][S]=max(dp[j-1][P]+value[f(t[i+j*k],S)],dp[j-1][R]+value[f(t[i+j*k],S)]);
			dp[j][P]=max(dp[j-1][R]+value[f(t[i+j*k],P)],dp[j-1][S]+value[f(t[i+j*k],P)]);
		}
		ans += max(dp[v[i].size()-1][P],max(dp[v[i].size()-1][R],dp[v[i].size()-1][S]));
	}
	cout << ans << endl;	
}
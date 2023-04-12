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

using namespace std;

ll cnt[1500010];
ll ans;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	vector<ll> a(n);
	cinf(a,n);
	rep(i,m)cnt[a[i]]++;
	rep(i,n+1){
		if(cnt[i]==0){
			ans=i;
			break;
		}
	}
	rep2(1,i,n-m+1){
		cnt[a[i-1]]--;
		cnt[a[i+m-1]]++;
		if(cnt[a[i-1]]==0)
			ans=min(ans,a[i-1]);
	}
	cout << ans << endl;
}
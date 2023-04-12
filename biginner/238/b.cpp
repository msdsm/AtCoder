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
	vector<ll> ans;
	ans.push_back(0);
	rep(i,n){
		rep(j,ans.size()){
			ans[j]+=a[i];
			ans[j]%=360;
		}
		ans.push_back(0);
	}
	sort(ans.begin(),ans.end());
	ll max = ans[0];
	rep2(1,i,ans.size()){
		if(max<ans[i]-ans[i-1])
			max=ans[i]-ans[i-1];
	}
	if(max<360-ans[ans.size()-1])
		max=360-ans[ans.size()-1];
	cout << max << endl;
}
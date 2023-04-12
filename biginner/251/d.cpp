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
	ll w;
	cin >> w;
	vector<ll> ans;
	vector<bool> d(w+1);
	d[0]=true;
	ll i = 1;
	set<ll> st;//２つの和
	while(i<=w){
		//cout << i << endl;
		while(i<=w&&d[i])i++;
		if(i>w)break;
		for(auto itr = st.begin();itr!=st.end();itr++){
			if(*itr+i <= w)
				d[*itr + i]=true;
		}
		rep(j,ans.size()){
			if(ans[j]+i <= w){
				d[ans[j]+i]=true;
				st.insert(ans[j]+i);
			}
		}
		ans.push_back(i);
		i++;
	}
	cout << ans.size() << endl;
	rep(i,ans.size())cout << ans[i] << ' ';
	cout << endl;
}
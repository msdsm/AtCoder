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

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll a,b;
	cin >> a >> b;
	set<ll> s,t;
	vector<ll> d;
	for(ll i = 1;i*i<=a;i++){
		if(a%i==0){
			s.insert(i);
			s.insert(a/i);
		}
	}
	for(ll i = 1;i*i<=b;i++){
		if(b%i==0){
			t.insert(i);
			t.insert(b/i);
		}
	}
	for(auto itr=s.begin();itr!=s.end();itr++){
		if(t.count(*itr)>0)
			d.push_back(*itr);
	}
	sort(d.begin(),d.end());
	vector<ll> ans;
	rep(i,d.size()){
		if(d[i]==1)
			continue;
		else{
			rep(j,ans.size()){
				if(d[i]%ans[j]==0)
					goto Exit;
			}
			ans.push_back(d[i]);
			Exit:;
		}
	}
	cout << ans.size()+1 << endl;	
}
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
	vector<pll> v(n);
	vector<pll> ans;
	pcin(v,n);
	vector<ll> mp(200010,0);
	rep(i,n){
		mp[v[i].fst]+=1;
		mp[v[i].snd]+=-1;
	}
	rep2(1,i,mp.size()){
		mp[i] += mp[i-1];
	}
	pll next;
/*
	cout << "debug start" << endl;
	rep(i,60)cout << i << ':' << mp[i] <<endl;
	cout << "debug end" << endl;
*/	
	
	bool zero=true;//前回0
	rep(i,mp.size()){
		if(zero){//前回0
			if(mp[i]>0){
				next.fst = i;
				zero = false;
			}else{//今回も0
				continue;
			}
		}else{//前回0でない
			if(mp[i]>0){
				continue;
			}else{
				zero = true;
				next.snd = i;
				ans.push_back(next);
			}
		}
	}
	rep(i,ans.size()){
		cout << ans[i].fst << ' ' << ans[i].snd << endl;
	}
}
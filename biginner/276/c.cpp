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
	vector<ll> p(n);
	vector<ll> ans;
	cinf(p,n);
	ll idx = 0;
	rep2(1,i,n){
		if(p[i-1]<p[i]){
			continue;
		}else{
			idx = i;
		}
	}
	idx--;
	ll tar = p[idx];
	vector<ll> v;
	for(ll i = idx+1;i<n;i++){
		v.push_back(p[i]);//昇順
	}
	//cout << idx << endl;
	//cout << tar << endl;
	auto itr = lower_bound(v.begin(),v.end(),tar);
	itr--;
	//cout << (*itr) << endl;
	rep(i,idx){
		ans.push_back(p[i]);
	}
	ans.push_back(*itr);
	v.erase(itr);
	v.push_back(tar);
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	rep(i,v.size()){
		ans.push_back(v[i]);
	}
	rep(i,n){
		cout<<ans[i]<<' ';
	}cout<<endl;
}
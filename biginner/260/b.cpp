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

bool f(pair<long long int,long long int> a,pair<long long int,long long int> b){
	if(a.fst != b.fst){
		return a.fst > b.fst;
	}else{
		return a.snd < b.snd;
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,x,y,z;
	cin >> n >> x >> y >> z;
	vector<ll> a(n),b(n);
	cinf(a,n);
	cinf(b,n);
	vector<pll> ma(n);
	rep(i,n){
		ma[i].fst = a[i];
		ma[i].snd = i;
	}
	sort(ma.begin(),ma.end(),f);
/*
	cout << "debug start" << endl;
	rep(i,n)cout << ma[i].fst << ' ' << ma[i].snd << endl;
	cout << "debug end" << endl;
*/	
	vector<bool> bl(n,false);
	vector<ll> ans;
	ll cnt = 0;
	ll idx = 0;
	while(cnt!=x){
		ans.push_back(ma[idx].snd+1);
		bl[ma[idx].snd]=true;
		cnt++;
		idx++;
	}	
	//cout << "あ" << endl;
	vector<pll> en(n);
	rep(i,n){
		en[i].fst = b[i];
		en[i].snd = i;
	}
	sort(en.begin(),en.end(),f);
	cnt = 0;
	idx = 0;
	while(cnt!=y){
		if(!bl[en[idx].snd]){
			bl[en[idx].snd]=true;
			cnt++;
			ans.push_back(en[idx].snd+1);
		}
		idx++;
	}
	//cout << "い" << endl;
	vector<pll> sum(n);
	rep(i,n){
		sum[i].fst = a[i]+b[i];
		sum[i].snd = i;
	}
	sort(sum.begin(),sum.end(),f);
	cnt=0;
	idx=0;
	while(cnt!=z){
		//cout <<'z' << sum[idx].snd << endl;
		if(!bl[sum[idx].snd]){
			bl[sum[idx].snd]=true;
			cnt++;
			ans.push_back(sum[idx].snd+1);
		}
		idx++;
	}
	sort(ans.begin(),ans.end());
	rep(i,ans.size()){
		cout << ans[i] << endl;
	}
}
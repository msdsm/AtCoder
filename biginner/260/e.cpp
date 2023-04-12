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
	ll n,m;
	cin >> n >> m;
	vector<pll> p(n);
	pcin(p,n);
	sort(p.begin(),p.end());
	vector<ll> mb(m+1,0);
	rep(i,n){
		mb[p[i].fst-1] = max(mb[p[i].fst-1],p[i].snd);
	}

	cout << "debug start" << endl;
	rep(i,m+1)cout << mb[i] << ' ';
	cout << "debug end" << endl;
	
	
	vector<ll> v(m);//v[i]:i+1から始まる最適な最小部分列サイズ
	ll l = 1;
	ll r = p[n-1].fst;
	v[0]= r-l+1;
	rep2(1,i,m){
		if(i==p[0].snd-1){
			l = i+1;
			r = p[n-1].snd;
			v[i] = max(ll(0),r-l+1);
			continue;
		}
		if(i>p[0].snd-1){
			v[i]=0;
			continue;
		}
		l = i+1;
		r = mb[i-1];
		v[i] = max(ll(0),r-l+1);
	}

	cout << "debug start" << endl;
	rep(i,m)cout << v[i] << endl;
	cout << "debug end" << endl;
	
	
	vector<ll> ans(m);
	rep(i,m){
		if(v[i]!=0){
			ans[v[i]-1]++;
		}
	}
	rep2(1,i,m){
		ans[i] += ans[i-1];
	}
	rep(i,m){
		ans[i] = min(ans[i],m-i);
	}
	rep(i,m){
		cout << ans[i] << ' ';
	}cout<<endl;
}
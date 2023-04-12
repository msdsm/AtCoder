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
	ll h,w;
	cin >> h >> w;
	vector<vector<char> > s(h),t(h);
	rep(i,h){
		s[i].resize(w);
		t[i].resize(w);
	}
	rep(i,h){
		rep(j,w){
			cin >> s[i][j];
		}
	}
	rep(i,h){
		rep(j,w){
			cin >> t[i][j];
		}
	}
	vector<string> vs(w),vt(w);
	rep(j,w){
		rep(i,h){
			vs[j].push_back(s[i][j]);
			vt[j].push_back(t[i][j]);
		}
	}
	sort(vs.begin(),vs.end());
	sort(vt.begin(),vt.end());
	rep(j,w){
		if(vs[j]!=vt[j]){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
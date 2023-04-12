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
	vector<string> s(n);
	cinf(s,n);
	vector<ll> ans(10);
	rep(index,10){
		vector<ll> v(10);
		rep(i,n){
			rep(j,s[i].length()){
				if(s[i][j]==char('0'+index))
					v[j]++;
			}
		}
		ll cnt = n;
		ll tmp = 0;
		while(cnt!=0){
			rep(i,10){
				if(v[i]>0){
					v[i]--;
					cnt--;
					if(cnt==0){
						ans[index]=10*tmp+i;
					}
				}
			}
			tmp++;
		}
	}
	sort(ans.begin(),ans.end());
	cout << ans[0] << endl;
}
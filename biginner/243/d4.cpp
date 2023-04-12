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
	vector<ll> v;
	ll inf = numeric_limits<ll>::max();
	//cout << inf << endl;
	ll n,x;
	cin >> n >> x;
	string s;
	cin >> s;
	v.push_back(x);
	rep(i,n){
		vector<ll> tmp;
		bool flag = false;
		if(s[i]=='R'){
			rep(j,v.size()){
				if(v[j]<inf/2-10){
					v[j] = v[j]*2+1;
				}else{//分割
					flag = true;
					if(v[j]%2==0){
						tmp.push_back(v[j]/2);
						v[j] /= 2;
					}else{
						tmp.push_back(v[j]/2+1);
						v[j] /= 2;
					}
					v[j] = 2*v[j];
					tmp[tmp.size()-1] = 2*tmp[tmp.size()-1]+1;
				}
			}
		}else if(s[i]=='L'){
			rep(j,v.size()){
				if(v[j]<inf/2-10){
					v[j] = v[j]*2;
				}else{//分割
					flag = true;
					if(v[j]%2==0){
						tmp.push_back(v[j]/2);
						v[j] /= 2;
					}else{
						tmp.push_back(v[j]/2+1);
						v[j] /= 2;
					}
					v[j] = 2*v[j];
					tmp[tmp.size()-1] = 2*tmp[tmp.size()-1];
				}
			}
		}else{
			rep(j,v.size()-1){
				if(v[j]%2==0){
					if(v[j]<v[j+1]){
						v[j]++;
						v[j+1]--;
					}else{
						v[j]--;
						v[j+1]++;
					}
				}
			}
			rep(j,v.size()){
				v[j]/=2;
			}
		}
		if(flag){
			rep(j,tmp.size()){
				v.push_back(tmp[j]);
			}
		}
	}
	ll ans = 0;
	rep(i,v.size()){
		ans += v[i];
	}
	cout << ans << endl;
}
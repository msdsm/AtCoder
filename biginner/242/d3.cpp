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

string s;

char f(ll x,ll y){
	if(x==0){
			return s[y];
		}else if(y==0){
			return char((s[0]-'A'+x)%3+'A');
		}else{
			if(y%2==0){
				return char((f(x-1,y/2)-'A'+1)%3+'A');
			}else{
				return char((f(x-1,(y-1)/2)-'A'+2)%3+'A');
			}
		}
	}


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	cin >> s;
	ll q;
	cin >> q;
	rep(i,q){
		ll t,k;
		cin >> t >> k;
		k--;
		cout << f(t,k) << endl;//stringの受け渡しはO(n)かかるから遅い
	}
}
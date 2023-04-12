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

ull cnt;
string ans;
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll a,b,k;
	cin>>a>>b>>k;
	ll e=0;
	rep(i,b){
		e+=2;
		e*=2;
	}
	//cout << e << endl;
	ld c = 1;
	rep(i,a){
		c*=(ld)(b+i+1)/(i+1);
	}
	ll tmp = c/2;
	//cout << tmp << endl;
	rep(i,e+1){
		if(bitset<64>(i).count()==b){
			cnt++;
			if(cnt==k){
				//cout << bitset<64>(i) << endl;
				ll tmp=i;
				rep(j,a+b){
					if(tmp%2==0)
						ans.push_back('a');
					else
						ans.push_back('b');
					tmp/=2;
				}
				reverse(ans.begin(),ans.end());
				cout << ans << endl;
				return 0;
			}
		}
	}
}
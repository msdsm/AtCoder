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

ll cnt;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	vector<ll> t(n),l(n),r(n);
	rep(i,n)cin>>t[i]>>l[i]>>r[i];
	rep(i,n){
		rep2(i+1,j,n){
			if(l[i]<r[j]&&l[j]<r[i])
				cnt++;
			else{
				if(l[i]==l[j]&&r[i]==r[j])
					cnt++;
				else if(r[i]==l[j]){
					if((t[i]==1||t[i]==3)&&(t[j]==1||t[j]==2)){
						cnt++;
					}
				}else if(r[j]==l[i]){
					if((t[j]==1||t[j]==3)&&(t[i]==1||t[i]==2))
						cnt++;
				}else{
					continue;
				}
			}
		}
	}
	cout << cnt << endl;
}
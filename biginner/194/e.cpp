//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

bool flag;
bool check;
bool check2;
ll tmp,tmp2;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll n,m;
	cin >> n >> m;
	vector<ll> a(n);
	cinf(a,n);
	rep(i,n){
		rep(j,n){
			if(a[j]==i){
				check2=false;
				if(check){
					if(j>tmp+m){
						flag=true;
						break;
					}else{
						tmp=j;
					}
				}else{
					check=true;
					tmp=j;
				}
			}else{
				if(check2){
					if(j>=tmp2+m-1){
						flag=true;
						break;
					}
				}else{
					check2=true;
					tmp2=j;
				}
			}
		}
		check=false;
		check2=false;
		if(flag){
			cout << i << endl;
			return 0;
		}
	}
}
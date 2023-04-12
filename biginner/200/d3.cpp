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

bool flag;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll data[200];
	rep(i,200)data[i]=0;
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n)a[i]%=200;
	cinf(a,n);
	int max = min(n,8);
	for(ll bits=1;bits<(1<<max);bits++){
		ll tmp=0;
		rep(i,max){
			if(bits&(1<<i)){
				tmp+=a[i]%200;
			}
		}
		data[tmp%200]++;
	}
	rep(i,200){
		if(data[i]>1){
			for(ll bits=1;bits<(1<<max);bits++){
				ll tmp=0;
				vector<int> t;
				rep(i,max){
					if(bits&(1<<i)){
						tmp+=a[i];
						t.push_back(i+1);
					}
				}
				tmp%=200;
				if(tmp==i){
					if(flag){
						cout << t.size() << ' ';
						rep(j,t.size()){
							if(j==t.size()-1)
								cout << t[j] << endl;
							else
								cout << t[j] << ' ';
						}
						break;
					}else{
						cout << "Yes" << endl;
						cout << t.size() << ' ';
						rep(j,t.size()){
							if(j==t.size()-1)
								cout << t[j] << endl;
							else
								cout << t[j] << ' ';
						}
						flag = true;
					}
				}
			}
			return 0;
		}
	}
	cout << "No" << endl;
}
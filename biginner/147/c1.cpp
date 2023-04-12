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

int cnt;
bool flag;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	int max = 0;
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> x(n),y(n);
	rep(i,n){
		cin >> a[i];
		rep(j,a[i]){
			int tmp1,tmp2;
			cin >> tmp1 >> tmp2;
			x[i].push_back(tmp1);
			y[i].push_back(tmp2);
		}
	}
	for(ll bits=0;bits<(1<<n);bits++){
		set<int> st1,st2;
		cnt=0;
		rep(i,n){
			if(bits&(1<<i)){
				st1.insert(i);
				cnt++;
			}
			else
				st2.insert(i);
		}
		for(auto itr=st1.begin();itr!=st1.end();itr++){
			rep(i,a[*itr]){
				if(y[*itr][i]==1){
					if(st1.count(x[*itr][i]-1)>0)
						continue;
					else
						goto Exit;
				}else{
					if(st2.count(x[*itr][i]-1)>0)
						continue;
					else
						goto Exit;
				}
			}
		}
		if(max<cnt)max=cnt;
		Exit:;
	}
	cout << max << endl;
}
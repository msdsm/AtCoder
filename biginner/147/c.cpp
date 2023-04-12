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

/*
	cout << "debug start" << endl;
	rep(i,n){
		cout << a[i] << endl;
		rep(j,a[i]){
			cout << x[i][j] << ' ' << y[i][j] << endl;
		}
		cout << endl;
	}
	cout << "debug end" << endl;
*/
	for(ll bits=0;bits < (1<<n);bits++){
		for(int i=0;i<n;i++){
			if(bits&(1<<i)){
				rep(j,a[i]){
/*
					cout << "debug start" << endl;
					cout << bitset<15>(bits) << endl;
					cout << x[i][j] << endl;
					cout << y[i][j] << endl;
					cout << (bits&(1<<(x[i][j]-1))) << endl;
					cout << "debug end" << endl;
*/					
					
					if((y[i][j]==1)&&((bits&(1<<(x[i][j]-1)))==0)){
						flag = true;
						break;
					}
					if((y[i][j]==0)&&((bits&(1<<(x[i][j]-1)))!=0)){
						flag = true;
						break;
					}
					if(j==a[i]-1)
						cnt++;
				}
/*
				cout << "debug start" << endl;
				cout << bitset<15>(bits) << endl;
				cout << cnt << endl;
				cout << "debug end" << endl;
*/				
				if(flag){
					cnt=0;
					break;	
				}
			}
		}
		if(max<cnt)
			max=cnt;
		cnt=0;
		flag = false;
	}
	cout << max << endl;	
}
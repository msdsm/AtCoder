#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int cnt;

int main(){
	int n;
	cin >> n;
	vector<double> x(n),y(n);
	rep(i,n)cin >> x[i] >> y[i];
	rep(i,n){
		arep(i+1,j,n){
			if(abs((y[i]-y[j])/(x[i]-x[j]))<=1)
				cnt++;
		}
	}
	cout << cnt << endl;
}
#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

string a[51];
string b[51];

int main(){
	int n,m;
	cin >> n >> m;
	rep(i,n)cin>>a[i];
	rep(i,m)cin>>b[i];
	rep(i,n-m+1){
		rep(j,n-m+1){
			rep(k,m){
				if(a[i+k].substr(j,m)!=b[k])break;
				else if(k==m-1){
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
}
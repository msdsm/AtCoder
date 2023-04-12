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
	int d1[n];
	int d2[n];
	rep(i,n){
		cin >> d1[i] >> d2[i];
	}
	rep(i,n){
		if(d1[i]==d2[i]){
			cnt++;
			if(cnt==3){
				cout << "Yes" << endl;
				return 0;
			}
		}
		else
			cnt=0;
	}
	cout << "No" << endl;
}
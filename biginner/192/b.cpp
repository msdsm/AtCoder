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

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	string s;
	cin >> s;
	rep(i,s.length()){
		if(i%2==0){
			if(!(s[i]>='a'&&s[i]<='z')){
				cout << "No" << endl;
				return 0;
			}
		}else{
			if(!(s[i]>='A'&&s[i]<='Z')){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}
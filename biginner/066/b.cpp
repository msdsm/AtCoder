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
	string s;
	cin >> s;
	while(true){
		s.erase(s.begin()+s.length()-1);
		s.erase(s.begin()+s.length()-1);
		if(s.substr(0,s.length()/2)==s.substr(s.length()/2,s.length()/2)){
			cout << s.length() << endl;
			return 0;
		}
	}
}
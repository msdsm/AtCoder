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
	ll n,x;
	cin >> n >> x;
	string s;
	cin >> s;
	rep(i,s.length()){
		if(s[i]=='o'){
			x++;
		}else{
			if(x>0)
				x--;
		}
	}
	cout << x << endl;
}
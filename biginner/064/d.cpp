#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll l;
ll r;
bool flag;

int main(){
	ll n;
	string s;
	cin >> n;
	cin >> s;
	rep(i,n){
		if(s[i]=='('){
			if(flag){
				r++;
			}else{
				flag=true;
			}
		}else{
			if(flag){
				flag=false;
			}else{
				l++;
			}
		}
	}
	if(flag)r++;
	rep(i,l)cout<<'(';
	cout << s;
	rep(i,r)cout<<')';
	cout<<endl;
}
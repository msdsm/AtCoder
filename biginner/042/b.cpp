#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

string s[101];
string ans;

int main(){
	ll n,l;
	cin >> n >> l;
	rep(i,n){
		cin >> s[i];
	}
	rep(i,n){
		for(ll j=n-2;j>=i;j--){
			rep(k,l){
				if(s[j][k]>s[j+1][k]){
					swap(s[j],s[j+1]);
					break;
				}else if(s[j][k]<s[j+1][k]){
					break;
				}
			}
		}
	}
	rep(i,n){
		cout << s[i];
	}
	cout << endl;


	/*debug
	rep(i,n){
		cout << s[i] << endl;
	}*/
}
#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int alpha[26];
string s[51];

int main(){
	int n;
	cin >> n;
	rep(i,n)cin>>s[i];
	rep(i,s[0].length())alpha[s[0][i]-'a']++;
	arep(1,i,n){
		rep(j,26){
//cout << s[i].find(static_cast<char>(j+'a')) << endl;
			if(s[i].find(static_cast<char>(j+'a'))>=s[i].length())
				alpha[j]--;
		}
	}
	rep(i,26){
		rep(j,alpha[i]){
			cout << static_cast<char>(i+'a');
		}
	}
	cout << endl;
}
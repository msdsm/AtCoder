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
	string s1,s2,s3;
	cin >> s1 >> s2 >> s3;
	cout << static_cast<char>(s1.c_str()[0]-'a'+'A') << static_cast<char>(s2.c_str()[0]-'a'+'A') << static_cast<char>(s3.c_str()[0]-'a'+'A') << endl;
}
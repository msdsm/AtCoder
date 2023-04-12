#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;


ll str_len(char *s){
  ll len;
  while(*s++)
    len++;
  return len;
}

bool judge(char *s,char *t,ll n){
	rep(i,n){
		if(s[i]!=t[i])
			return false;
	}
	return true;
}

int main(){
	char s[100],t[100];
	cin >> s >> t;
	if(str_len(t)==str_len(s)+1 && judge(s,t,str_len(s))==true)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
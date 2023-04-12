#include <iostream>
#include <algorithm>
#include <string>
#define rep(a,i,n) for(int i=(a);i<(n);i++)

using namespace std;

int main(){
	int n,tmp=0;
	cin >> n;
	string s[n];
	rep(0,i,n){
		cin >> s[i];
	}
	sort(s,s+n);
	rep(0,i,n-1){
		if(s[i] == s[i+1])
			tmp++;
	}
	cout << n-tmp << endl;
}
#include <iostream>
#include <string>
#define rep(a,i,n) for(int i=(a);i<(n);i++)

using namespace std;

int main(){
	int n,count,tmp=0;
	cin >> n;
	string s[n];
	rep(0,i,n){
		cin >> s[i];
		rep(0,j,i){
			if(s[i] == s[j]){
				tmp++;
				break;
			}
		}
	}
	count = n - tmp;
	cout << count << endl;
}

/* 実行結果はTLE */ 
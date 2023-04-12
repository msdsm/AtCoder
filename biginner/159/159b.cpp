#include <iostream>
#define N 10000 
#define rep(a,i,n) for(ll i=(a);i<(n);i++)
typedef long long ll;

using namespace std;

ll str_len(char *s){
	ll len = 0;
	while(*s++)
		len++;
	return len;
}

bool palindrome(char *s,ll a,ll n){
	rep(a,i,n/2+1){
		if(s[i] != s[n-i-1])
			return false;
	}
	return true;
}

int main(){
	char s[N];
	cin >> s;
	ll n = str_len(s);
	if(palindrome(s,0,n)==true && palindrome(s,0,((n-1)/2))==true && palindrome(s,(n+1)/2,n)==true)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
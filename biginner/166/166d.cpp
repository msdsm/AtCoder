#include <iostream>
typedef long long ll;

using namespace std;

ll beki5(ll x){
	ll r = 1;
	for(ll i=0;i<5;i++){
		r *= x;
	}
	return r;
}

int main(){
	ll x,a,b;
	cin >> x;
	for(a=64;a>-1000;a--){
		for(b=a-1;b>-1000;b--){
			if(beki5(a)-beki5(b) == x)
				goto EXIT;
		}
	}
	EXIT: cout << a << ' ' << b << endl;
}

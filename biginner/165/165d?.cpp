#include <iostream>
#include <algorithm>
#define rep(a,i,n) for(int i=(a);i<(n);i++)
typedef long long ll;

using namespace std;

int main(){
	ll a,b,n;
	cin >> a >> b >> n;
	ll f[n+1];
	rep(0,i,n+1){
		f[i] = a*i/b - a*(i/b);
	}
	sort(f,f+n+1);
	cout << f[n] << endl;
}
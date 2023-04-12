#include <iostream>
#define min(a,b)((a)>(b))?(b):(a)
typedef long long ll;

using namespace std;

ll f(ll r,ll a,ll b){
	return a*r/b;
}

int main(){
	ll a,b,n,ans;
	cin >> a >> b >> n;
	ans = f(min(b-1,n),a,b);
	cout << ans << endl;
}
#include <iostream>
#include <cmath>
#define rep(a,i,n) for(int i=(a);i<(n);i++)
#define mod 1000000007
typedef long long ll;

using namespace std;

int main(){
	ll n,k,max=0,min=0,sum=0;
	cin >> n;
	cin >> k;
	rep(0,i,n+1){
		max += n-i;
		min += i;
		if(i < k-1)
			continue;
		sum += max - min + 1;
	}
	cout << sum%mod << endl;
}
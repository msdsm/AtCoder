#include <iostream>
#define rep(a,i,n) for(int i=(a);i<(n);i++)
#define ZERO 0
typedef long long ll;
using namespace std;

void set_one(ll *a,ll n){
	rep(0,i,n){
		a[i] = 1;
	}
}

int main(){
	ll n,m,count=0;
	cin >> n >> m;

	ll h[n];
	rep(0,i,n){
		cin >> h[i];
	}

	ll a[m],b[m];
	rep(0,i,m){
		cin >> a[i] >> b[i];
	}

	ll s[n];
	set_one(s,n);

	rep(0,i,m){
		if(h[a[i]-1] > h[b[i]-1])
			s[b[i]-1] = ZERO;
		else if(h[a[i]-1] < h[b[i]-1])
			s[a[i]-1] = ZERO;
		else if(h[a[i]-1] == h[b[i]-1]){
			s[a[i]-1] = ZERO;
			s[b[i]-1] = ZERO;
		}
	}

	rep(0,i,n){
		if(s[i] != ZERO)
			count++;
	}
	cout << count << endl;
}
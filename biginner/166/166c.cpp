#include <iostream>
#define rep(a,i,n) for(int i=(a);i<(n);i++)
typedef long long ll;

using namespace std;

void set_zero(ll *a,ll n){
	rep(0,i,n){
		a[i] = 0;
	}
}

int main(){
	ll n,m,count=0;
	cin >> n >> m;
	ll h[n],a[m],b[m];

	set_zero(a,m);
	set_zero(b,m);

	rep(0,i,n){
		cin >> h[i];
	}

	rep(0,i,m){
		cin >> a[i] >> b[i];
	}

	rep(0,i,n){
		rep(0,j,m){
			if(a[j] == i+1){
				if(h[i] < h[b[j]-1]){
					goto Exit;
				}
			}
			if(b[j] == i+1){
				if(h[i] < h[a[j]-1]){
					goto Exit;
				}
			}
		}
		count++;
		Exit:
		;
	}
	cout << count << endl;
}
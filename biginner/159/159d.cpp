#include <iostream>
#include <algorithm>
#define rep(a,i,n) for(int i=(a);i<(n);i++)
typedef long long ll;

using namespace std;

void count_seq(ll *d,const ll *s,ll n){
	rep(0,i,n){
		d[s[i]]++;
	}
}



ll selection(const ll *b,const ll *a,ll n,ll i){
	ll sum=0;
	rep(1,j,a[i]){
		sum += b[j]*(b[j]-1)/2;
	}
	sum += (b[a[i]]-1)*(b[a[i]]-2)/2;
	rep(a[i]+1,j,n+1){
		sum += b[j]*(b[j]-1)/2;
	}
	return sum;
}

int main(){
	ll n;
	cin >> n;
	ll a[n],b[n+1];
	rep(0,i,n){
		cin >> a[i];
		b[i+1] = 0;
	}
	count_seq(b,a,n);
	rep(0,i,n){
		cout << selection(b,a,n,i) << endl;
	}
}
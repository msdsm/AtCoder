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

ll count(ll *b,ll n){
	ll sum=0;
	rep(1,i,n+1){
		sum += b[i]*(b[i]-1)/2;
	}
	return sum;
}

ll selection(const ll *b,const ll *a,ll n,ll i,ll sum){
	sum = sum + (b[a[i]]-1)*(b[a[i]]-2)/2 - (b[a[i]])*(b[a[i]]-1)/2;
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
	ll sum = count(b,n);
	rep(0,i,n){
		cout << selection(b,a,n,i,sum) << endl;
	}
}
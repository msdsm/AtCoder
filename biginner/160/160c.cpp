#include <iostream>
#include <algorithm>
#define rep(a,i,n) for(int i=(a);i<(n);i++)

using namespace std;

int diff(int a,int b){
	return (a>b)?a-b:b-a;
}

int main(){
	int k,n;
	cin >> k;
	cin >> n;
	int a[n];
	rep(0,i,n){
		cin >> a[i];
	}
	int b[n];
	rep(0,i,n-1){
		b[i] = diff(a[i],a[i+1]);
	}
	b[n-1] = k-a[n-1]+a[0];
	sort(b,b+n);
	cout << k-b[n-1] << endl;
}
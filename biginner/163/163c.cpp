#include <iostream>
#include <cmath>
#define rep(a,i,n) for(int i=(a);i<(n);i++)

using namespace std;

void set_seq(const int a[],int b[],int n){
	rep(0,i,n-1){
		b[a[i]-1]++;
	}
}

int main(){
	int n;
	cin >> n;
	int a[n-1],b[n];
	rep(0,i,n-1){
		cin >> a[i];
		b[i] = 0;
	}
	b[n-1] = 0;
	set_seq(a,b,n);
	rep(0,i,n){
		cout << b[i] << endl;
	}
}
#include <iostream>
#include <cmath>
#define rep(a,i,n) for(int i=(a);i<(n);i++)
using ll = long long;
using namespace std;

int main(){
int n,m,flag,sum=0;
cin >> n;
cin >> m;
int a[m];
rep(0,i,m){
	cin >> a[i];
	sum += a[i];
}
if(n>=sum)
	flag = n-sum;
else
	flag = -1;
cout << flag << endl;
}
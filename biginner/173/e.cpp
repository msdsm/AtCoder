#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef struct {
	ull num;
	bool sign;
} data;

using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	data a[n];
	ll tmp;
	rep(i,n){
		cin >> tmp;
		if(tmp>=0){
			a[i].num=tmp;
			a[i].sign=true;
		}
		else{
			a[i].num=-tmp;
			a[i].sign=false;
		}
	}
}
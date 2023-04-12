#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define cinfzero(x,n) for(int i=0;i<(n);i++)x[i]=0;
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
using namespace std;
 
 
class Roop{
public:
	ll n;
	ll start;
};
 
ll move(const ll *a,ll start,ll tmp){
	if(tmp!=0)
		return move(a,a[start-1],tmp-1);
	else
		return start;
}
 
ll judge(ll *b,ll tmp,ll x){
	rep(i,tmp){
		if(x==b[i])
			return i;
	}
	return -1;
}
 
Roop search(const ll *a,ll start,ll tmp,ll *b){
	ll j = judge(b,tmp,start);
	if(j==-1){
		b[tmp]= start;
		return search(a,a[start-1],tmp+1,b);
	}
	else{
		Roop rp;
		rp.n=tmp-j;
		rp.start=j;
		return rp;
	}
}
 
 
int main(){
	ll n,k;
	cin >> n >> k;
	ll a[n],b[n];
	cinf(a,n);
	cinfzero(b,n);
	Roop rp = search(a,1,0,b);
	if(k < rp.start){
		cout << b[k] << endl;
	}else{
		k = rp.start + (k-rp.start)%rp.n;
		cout << b[k] << endl;
	}
}
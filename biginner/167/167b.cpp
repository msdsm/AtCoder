#include <iostream>

#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;



int main(){
	ll a,b,c,k,sum=0;
	cin >> a >> b >> c >> k;
	while(k!=0){
		if(a!=0){
			sum+=1;
			a--;
		}
		else if(b!=0){
			sum+=0;
			b--;
		}
		else if(c!=0){
			sum-=1;
			c--;
		}
		k--;
	}
	cout << sum << endl;
}
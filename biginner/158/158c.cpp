#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
#define N 100000
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll set_seq(ll *ary,ld rate,ll tax){
	ll i=0;
	if(tax/rate-static_cast<ll>(tax/rate)==0.00)
		ary[0] = static_cast<ll>(tax/rate);
	else
		ary[0] = static_cast<ll>(tax/rate+1);
	while(rate*(ary[i])<=tax+1){
		i++;
		ary[i]=ary[0]+i;
	}
	return i;
}

const ll KEY_NOT_FOUND = -1;
ll binary_search(ll *ary,ll key,ll imin,ll imax){
	if(imin > imax)
		return KEY_NOT_FOUND;
	else{
		ll imid = imin + (imax-imin)/2;
		if(ary[imid] > key)
			return binary_search(ary,key,imin,imid-1);
		else if(ary[imid] < key)
			return binary_search(ary,key,imid+1,imax);
		else
			return imid;
	}
}

int main(){
	ll a,b;
	cin >> a >> b;
	ll bb[10];
	bb[0] = 10*b;
	arep(1,i,10){
		bb[i] = 10*b+i;
	}
	ll aa[N];
	ll n = set_seq(aa,0.08,a);
	ll i=0;
	while(binary_search(bb,aa[i],0,9)==KEY_NOT_FOUND){
		if(i==n-1){
			cout << KEY_NOT_FOUND << endl;
			return 0;
		}
		i++;
	}	
	cout << bb[binary_search(bb,aa[i],0,n)] << endl;
}
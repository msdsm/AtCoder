//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

/*nCk*/
template <class Type>
Type combination(Type n,Type k){
  if(n==k || n==0 || n==1 || k==0)
    return 1;
  else
    return (combination(n-1,k)+combination(n-1,k-1));
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	ll l;
	cin >> l;
	cout << combination(l-1,(ll)11) << endl;
}
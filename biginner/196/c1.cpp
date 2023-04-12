//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ull cnt;

/*整数の桁数をO(1)で計算*/
template <class Type>
Type digit(Type n){
  if(n==0)
    return 1;
  return 1+floor(log10(n));
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	ll d = digit(n);
	if(d%2==1)d++;
	for(int i = 2;i<d;i+=2){
		cnt += 9*powl(10,i/2-1);
	}

/*
	cout << "debug start" << endl;
	cout << cnt << endl;
	cout << "debug end" << endl;
*/
	ll k = floor((ld)n/(powl(10,d/2)+1)+1-powl(10,d/2-1));
	//cout << k << endl;
	cout << cnt+k << endl;
}
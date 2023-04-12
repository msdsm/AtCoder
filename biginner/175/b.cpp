#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll L[101];
ll ans;

int main(){
	ll n;
	cin >> n;
	cinf(L,n);
	rep(i,n){
		arep(i+1,j,n){
			arep(j+1,k,n){
				if(L[i]+L[j]>L[k] && L[j]+L[k]>L[i] && L[k]+L[i]>L[j] && L[i]!=L[j] && L[j]!=L[k] && L[k]!=L[i])
					ans++;
				//cout << i << "," << j << "," << k<< endl;
			}
		}
	}
	cout << ans << endl;
}
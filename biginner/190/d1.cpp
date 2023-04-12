#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll cnt;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n;
	cin >> n;
	for(ll i = 1; i*i <= n;i++){
		if(static_cast<ld>(n)/i==static_cast<ld>(n/i) && i%2==1){


			cout << "debug start" << endl;
			cout << i << endl;
			cout << "debug end" << endl;



			cnt++;
			if((n/i)%2==1 && i!=n/i){

				cout << "debug start" << endl;
				cout << i << endl;
				cout << "debug end" << endl;
				
				
				cnt++;
			}
		}
	}

	for(ll i = 1; i*i <= 2*n;i++){
		if(static_cast<ld>(2*n)/i==static_cast<ld>(2*n/i)){
			if(static_cast<ld>(n)/i!=static_cast<ld>(n/i) && i%2==0){
			cnt++;

			cout << "あdebug start" << endl;
			cout << i << endl;
			cout << "debug end" << endl;
			}
			
			if((2*n/i)%2==0 && static_cast<ld>(n)/(2*n/i)!=static_cast<ld>(n/(2*n/i)) && i!=2*n/i){	
				cnt++;


				cout << "あdebug start" << endl;
				cout << i << endl;
				cout << "debug end" << endl;
			}
			
		}
	}
	cout << cnt << endl;
}
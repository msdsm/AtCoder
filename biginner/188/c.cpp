#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll tmp;

int main(){
	ll n;
	cin >> n;
	vector<ll> v;
	rep(i,1<<n){
		cin >> tmp;
		v.push_back(tmp);
	}

//cout << "あ" << endl;

	rep(i,n){

//cout << "い" << endl;

		if(i==n-1){
			if(v[0]<v[1])
				cout << v[0] << endl;
			else
				cout << v[1] << endl;
			exit(0);
			}

		for(ll j=0;j<(1<<(n-i));j+=2){

/*cout << "う" << endl;
cout << v[j] << endl;
cout << v[j+1] << endl;
*/

			if(v[j]<v[j+1])
				tmp=v[j];
			else
				tmp=v[j+1];
			vector<ll>::iterator itr = find(v.begin() , v.end() , tmp);
			v.erase(v.begin() + itr);
		}
	}
}
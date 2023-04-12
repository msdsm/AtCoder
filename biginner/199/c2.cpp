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

ll cnt;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	string s;
	cin >> s;
	string u = s.substr(0,n);
	string v = s.substr(n,n);
/*
	cout << "debug start" << endl;
	cout << u << endl;
	cout << v << endl;
	cout << "debug end" << endl;
*/	
	
	ll q;
	cin >> q;
	rep(i,q){
		ll t,a,b;
		cin >> t >> a >> b;
		if(t==2){
			cnt++;
		}else{
			if(cnt%2==1){
				if(b<=n){
					char c = v[a-1];
					v[a-1] = v[b-1];
					v[b-1] = c;
				}else if(a<=n){
					//cout << "あ" << endl;
					char c = v[a-1];
					v[a-1] = u[b-1-n];
					u[b-1-n] = c;
				}else{
					char c = u[a-1-n];
					u[a-1-n] = u[b-1-n];
					u[b-1-n] = c;
				}
			}else{
				if(b<=n){
					char c = u[a-1];
					u[a-1] = u[b-1];
					u[b-1] = c;
				}else if(a<=n){
					char c = u[a-1];
					u[a-1] = v[b-1-n];
					v[b-1-n] = c;
				}else{
					char c = v[a-1-n];
					v[a-1-n] = v[b-1-n];
					v[b-1-n] = c;
				}
			}
		}	
	}
	if(cnt%2==0)
		cout << u+v << endl;
	else
		cout << v+u << endl;
}
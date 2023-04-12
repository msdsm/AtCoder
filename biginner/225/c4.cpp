//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
#define fst first
#define snd second
#define pcin(x,n) for(ll i=0;i<(n);i++)cin>>x[i].fst>>x[i].snd;
#define pdebug(x) cout << '(' << x.fst << ',' << x.snd << ")\n";
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	ll b[n][m];
	rep(i,n)rep(j,m)cin>>b[i][j];
	rep(i,n)rep(j,m){
		b[i][j]--;
	}

	if(n!=1){
		rep(j,m){
			rep2(1,i,n){
				if(b[i][j]==b[i-1][j]+7)
					continue;
				else{
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}
	if(m!=1){
		rep(i,n){
			rep2(1,j,m){
				if(b[i][j]!=b[i][j-1]+1 || b[i][j]%7==0){
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}
	cout << "Yes" << endl;
}
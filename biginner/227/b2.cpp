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

ll cnt;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	int n;
	cin >> n;
	vector<ll> s(n);
	cinf(s,n);
	ll a[150][150];
	rep(i,150){
		rep(j,150){
			a[i][j] = 4*i*j+3*i+3*j;
		}
	}

	cout << "debug start" << endl;
	rep(i,150){
		rep(j,150){
			if(j!=150-1)
				cout << a[i][j] << ' ';
			else
				cout << a[i][j] << endl;
		}
	}
	cout << "debug end" << endl;
	
	
	bool flag = false;
	rep(i,n){
		rep(j,150){
			rep(k,150){
				if(a[j][k]==s[i])
					flag = true;
			}
		}
		if(!flag)
			cnt++;
		flag = false;
	}
	cout << cnt << endl;
}
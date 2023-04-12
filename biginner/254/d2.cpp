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
	ll n;
	cin >> n;
	vector<bool> sq(n+1,false);
	for(ll i = 1; i*i <= n; i++){
		sq[i*i] = true;
	}
/*
	cout << "debug start square" << endl;
	rep(i,n+1)cout << sq[i] << ' ';cout<<endl;
	cout << "debug end" << endl;
*/	
	
	vector<vector<ll> > d(n+1);//d[i]...iの約数を昇順
	rep2(1,i,n+1){
		for(ll j = i; j <= n; j += i){
			d[j].push_back(i);
		}
	}
/*
	cout << "debug start d" << endl;
	rep(i,n+1){
		rep(j,d[i].size()){
			cout << d[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;
*/	
	
	vector<ll> cnt(n+1);
	vector<ll> v(n);
	rep2(1,i,n+1){
		ll tmp=1;

	//	cout << i<< ':' << endl;
		
		
		
		rep(j,d[i].size()){
/*
			cout << "debug start" << endl;
			cout << d[i][d[i].size()-j-1] << endl;
			cout << sq[d[i][d[i].size()-j-1]] << endl;
			cout << "debug end" << endl;
*/			
			
			if(sq[d[i][d[i].size()-j-1]]){
				tmp = d[i][d[i].size()-j-1];
				break;
			}
		}
/*
		cout << "debug start tmp" << endl;
		cout << tmp << endl;
		cout << "debug end" << endl;
*/		
		
		cnt[i/tmp]++;
		v[i-1] = i/tmp;
	}
	ll ans = 0;
	rep(i,n){
		ans += cnt[v[i]];
	}

/*
	cout << "debug start cnt" << endl;
	rep(i,n+1)cout<<cnt[i]<<' ';cout<<endl;
	cout << "debug end" << endl;
*/	
	/*
	cout << "debug start v" << endl;
	rep(i,n)cout << v[i] << ' ';cout << endl;
	cout << "debug end" << endl;
	*/
	
	cout << ans << endl;
}
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
	if(m==0){
		cout << "Yes" << endl;
		return 0;
	}
	vector<pll> x(m);
	vector<pll> y(m);
	pcin(x,m);
	pcin(y,m);
	vector<vector<ll> > p1(n),p2(n);
	rep(i,m){
		p1[x[i].fst-1].push_back(x[i].snd-1);
		p2[y[i].fst-1].push_back(y[i].snd-1);
	}
/*
	cout << "debug start" << endl;
	rep(i,n){
		rep(j,p2[i].size()){
			cout << p2[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;
*/	
	vector<ll> v;
	rep(i,n){
		v.push_back(i);
	}
	do{
		bool flag = false;
		//rep(k,n)cout << v[k] << ' ';
		//cout << endl;
		rep(i,m){
			ll tmp1 = min(v[x[i].fst-1],v[x[i].snd-1]);
			ll tmp2 = max(v[x[i].fst-1],v[x[i].snd-1]);
/*			
			cout <<  "あいうえお" << i << endl;
			cout << v[x[i].fst-1] << endl;
			cout << v[x[i].snd-1] << endl;
			cout << tmp1 << endl;
			cout << tmp2 << endl;
*/
			if(p2[tmp1].size()==0){
				break;
			}
			rep(j,p2[tmp1].size()){
				//cout << p2[tmp1][j] << endl;
				if(p2[tmp1][j]==tmp2){
					flag = true;
					break;
				}
				if(j==p2[tmp1].size()-1)
					flag = false;
			}
			if(!flag)
				break;
			if(i==m-1){
				cout << "Yes" << endl;
				//rep(k,n)cout << v[k] << endl;
				return 0;
			}
		}
	}while(next_permutation(v.begin(),v.end()));
	cout << "No" << endl;
}
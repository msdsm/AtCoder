#pragma GCC optimize("Ofast")
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

vector<vector<ll> > path(200010);
vector<ll> in(200010);
ll n,m;
bool ans=false;

vector<ll> val(200010);

ll limit;

void dfs(ll node, ll num){
	limit++;
	if(limit>100000000){
		cout << "No" << endl;
		exit(0);
	}
	if(ans){
		return;
	}
	val[node] = num;
/*
	cout << "debug start" << endl;
	cout << node << endl;
	cout << num << endl;
	rep(i,n)cout<<val[i]<<' ';
		cout<<endl;
	cout << "debug end" << endl;
*/	
	rep(i,path[node].size()){
		ll next = path[node][i];
		if(val[next]==0){//未訪問
			if(num+1==n){//終了
				ans = true;
				val[next] = n;
				cout << "Yes" << endl;
				rep(jjj,n){
					cout<<val[jjj]<<' ';
				}cout<<endl;
				//cout << "あ" << endl;
				exit(0);
			}
			dfs(next, num+1);
		}
	}
	val[node] = 0;
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	cin >> n >> m;
	vector<pll> p(m);
	pcin(p,m);
	rep(i,m){
		p[i].fst--;
		p[i].snd--;
		path[p[i].fst].push_back(p[i].snd);
		in[p[i].snd]++;
	}
	ll cnt = 0;
	ll start;
	rep(i,n){
		if(in[i]==0){
			cnt++;
			start = i;
		}
	}
	if(cnt!=1){
		cout << "No" << endl;
		return 0;
	}
/*
	cout << "debug start start" << endl;
	cout << start << endl;
	cout << "debug end" << endl;
*/	
	
	dfs(start, 1);
	cout << "No" << endl;
}
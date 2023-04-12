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
	vector<pll> p(m);
	pcin(p,m);
	vector<vector<ll> > path(n);
	rep(i,m){
		p[i].fst--;
		p[i].snd--;
		path[p[i].fst].push_back(p[i].snd);
		path[p[i].snd].push_back(p[i].fst);
	}
	stack<ll> s;
	s.push(0);
	vector<bool> visited(n);
	visited[0]=true;
	ll start;
	while(!s.empty()){
		ll tmp = s.top();
		s.pop();
		//cout << tmp << endl;
		ll cnt = 0;
		rep(i,path[tmp].size()){
			ll next = path[tmp][i];
			if(!visited[next]){
				s.push(next);
				visited[next]=true;
				cnt++;
			}
		}
		if(cnt==0){
			start = tmp;
			break;
		}
	}
	//cout << start << endl;
	ll pre,next;
	rep(i,n)visited[i]=false;
	rep(i,n){
		if(i==0){
			if(path[start].size()!=1){
				cout << "No" << endl;
				return 0;
			}else{
				pre = start;
				next = path[start][0];
				visited[start]=true;
			}
		}else if(i==n-1){
			if(path[next].size()!=1){
				cout << "No" << endl;
				return 0;
			}
		}else{
			ll now = next;
			visited[now]=true;
			if(path[now].size()!=2){
				cout << "No" << endl;
				return 0;
			}
			if(path[now][0]==pre)
				next = path[now][1];
			else
				next = path[now][0];

			if(visited[next]){
				cout << "No" << endl;
				return 0;
			}
			pre = now;
		}
	}
	cout << "Yes" << endl;
}
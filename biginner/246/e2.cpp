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

int dx[4]={-1,-1,1,1};
int dy[4]={-1,1,-1,1};

#define ppll pair<ll,pll>

ll inf = numeric_limits<ll>::max();

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	pll a,b;
	cin >> a.fst >> a.snd;
	cin >> b.fst >> b.snd;
	a.fst--;a.snd--;
	b.fst--;b.snd--;
	vector<string> s(n);
	rep(i,n)cin>>s[i];
	deque<ppll> dq;
	vector<vector<vector<ll > > > d(n, vector<vector<ll> >(n, vector<ll>(4,1e9)));
	vector<vector<vector<bool > > > v(n, vector<vector<bool> >(n, vector<bool>(4,false)));

	rep(i,4){
		d[a.fst][a.snd][i]=0;
		v[a.fst][a.snd][i]=true;
		pll next = pll(a.fst+dx[i],a.snd+dy[i]);
		if(next.fst>=0 && next.fst<n && next.snd>=0 && next.snd<n){
			if(s[next.fst][next.snd]=='.'){
				dq.push_back(ppll(i,pll(next.fst,next.snd)));
				d[next.fst][next.snd][i]=1;
			}
		}
	}
	while(!dq.empty()){
		ppll tmp = dq.front();
		dq.pop_front();
		pll pre = tmp.snd;
		ll direction = tmp.fst;
		if(pre==b){
			cout << d[pre.fst][pre.snd][direction] << endl;
			return 0;
		}
		if(v[pre.fst][pre.snd][direction])continue;
		rep(i,4){
			pll next = pll(pre.fst+dx[i],pre.snd+dy[i]);
			if(next.fst<ll(0)|| n<=next.fst)
				continue;
			if(next.snd<ll(0) || n<=next.snd)
				continue;
			if(v[next.fst][next.snd][i])
				continue;
			if(s[next.fst][next.snd]=='#')
				continue;
			if(i==direction && d[next.fst][next.snd][i]>d[pre.fst][pre.snd][direction]){
				d[next.fst][next.snd][i] = d[pre.fst][pre.snd][direction];
				dq.push_front(ppll(i,next));
			}else if(i!=direction && d[next.fst][next.snd][i]>d[pre.fst][pre.snd][direction]+1){
				d[next.fst][next.snd][i] = d[pre.fst][pre.snd][direction]+1;
				dq.push_back(ppll(i,next));
			}
		}
		v[pre.fst][pre.snd][direction]=true;
	}
	cout << -1 << endl;
}
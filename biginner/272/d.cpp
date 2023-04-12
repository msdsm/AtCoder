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

ll dx[2]={1,-1};
ll dy[2]={1,-1};

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	queue<pll> q;
	vector<pll> d;
	for(ll i = 0; i*i<=m;i++){
		for(ll j = 0; j*j<=m;j++){
			if(m==i*i+j*j)
				d.push_back(pll(i,j));
		}
	}
	q.push(pll(0,0));
	vector<vector<ll> > ans(n);
	ll inf = numeric_limits<ll>::max();
	rep(i,n)ans[i].resize(n,inf);
	ans[0][0]=0;
	while(!q.empty()){
		pll tmp = q.front();
		q.pop();
		rep(i,d.size()){
			rep(j,2){
				rep(k,2){
					pll next = pll(tmp.fst+powl(-1,j)*d[i].fst,tmp.snd+powl(-1,k)*d[i].snd);
					if(next.fst>=0&&next.fst<n&&next.snd>=0&&next.snd<n){
						if(ans[next.fst][next.snd]>ans[tmp.fst][tmp.snd]+1){
							ans[next.fst][next.snd]=ans[tmp.fst][tmp.snd]+1;
							q.push(next);
						}
					}
				}
			}
		}
	}
	rep(i,n){
		rep(j,n){
			if(ans[i][j]==inf)
				cout << -1 << ' ';
			else
				cout << ans[i][j] << ' ';
		}cout<<endl;
	}
}
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

using Graph = vector<vector<int> >;

// 探索
vector<bool> seen, finished;

// サイクル復元のための情報
int pos = -1; // サイクル中に含まれる頂点 pos
stack<int> hist; // 訪問履歴

void dfs(const Graph &G, int v, int p) {
    seen[v] = true;
    hist.push(v);
    for (auto nv : G[v]) {
        if (nv == p) continue; // 逆流を禁止する

        // 完全終了した頂点はスルー
        if (finished[nv]) continue;

        // サイクルを検出
        if (seen[nv] && !finished[nv]) {
            pos = nv;
            return;
        }

        // 再帰的に探索
        dfs(G, nv, v);

        // サイクル検出したならば真っ直ぐに抜けていく
        if (pos != -1) return;
    }
    hist.pop();
    finished[v] = true;
}


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	vector<ll> a(m),b(m);
	rep(i,m)cin>>a[i]>>b[i];
	rep(i,m){
		a[i]--;
		b[i]--;
	}
	vector<ll> cnt(n);
	rep(i,m){
		cnt[a[i]]++;
		cnt[b[i]]++;
	}
	
	rep(i,n){
		if(cnt[i]>2){
			cout << "No" << endl;
			return 0;
		}
	}

	Graph G(n);
    for (int i = 0; i < m; ++i) {
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
     // 探索
    pos = -1;
    dfs(G, 0, -1);

    if(!hist.empty())
    	cout << "Yes" << endl;
    else
    	cout << "No" << endl;
}
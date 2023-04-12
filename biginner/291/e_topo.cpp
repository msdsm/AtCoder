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


// グラフ、頂点の入次数、頂点数を受け取り、そのトポロジカルソートを記録した配列を返す関数
vector<ll> topological_sort(vector<vector<ll> > &G, vector<ll> &indegree, ll V) {
    // トポロジカルソートを記録する配列
    vector<ll> sorted_vertices;

    // 入次数が0の頂点を発見したら、処理待ち頂点としてキューに追加する
    ll cnt = 0;
    queue<ll> que;
    for (ll i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            cnt++;
            que.push(i);
        }
    }
    if(cnt>=2){
        cout << "No" << endl;
        exit(0);
    }

    // キューが空になるまで、操作1~3を繰り返す
    while (que.empty() == false) {
        // キューの先頭の頂点を取り出す
        ll v = que.front();
        que.pop();

        // その頂点と隣接している頂点の入次数を減らし、0になればキューに追加
        //ここで2つ追加するとアウト
        ll ccnntt = 0;
        for (ll i = 0; i < G[v].size(); i++) {
            ll u = G[v][i];
            indegree[u] -= 1;
            if(indegree[u] == 0){
                que.push(u);
                ccnntt++;
            }
        }
        if(ccnntt>=2){
            cout << "No" << endl;
            exit(0);
        }
        // 頂点vを配列の末尾に追加する 
        sorted_vertices.push_back(v);
    }

    // トポロジカルソートを返す
    return sorted_vertices;
}

int main(void) {
    // 頂点数と辺の本数
    ll V, E;
    cin >> V >> E;

    // 隣接リストにより表現されるグラフ
    vector<vector<ll> > G(V);
    // 頂点の入次数を記録する配列
    vector<ll> indegree(V);
    for (ll i = 0; i < E; i++) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        indegree[v] += 1;
    }

    // トポロジカルソートする
    vector<ll> sorted_vertices = topological_sort(G, indegree, V);

    // トポロジカルソートを出力
    vector<ll> ans(V);
    for (ll i = 0; i < sorted_vertices.size(); i++) {
        //cout << sorted_vertices[i] << endl;
        ans[sorted_vertices[i]] = i+1;
    }
    cout << "Yes" << endl;
    rep(i,V)cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
};
using Graph = vector<vector<Edge> >;

// 深さ優先探索
vector<bool> seen;  // 探索したか記録
void dfs(const Graph &G, int v) {
    seen[v] = true;
    for (auto e : G[v]) {
        if (!seen[e.to]) {  // 訪問済みでなければ探索
            dfs(G, e.to);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    Graph G(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        Edge tmp2;
        tmp2.to = b;
        cin >> a >> b;
        vector<Edge> tmp(1);
        tmp[0]=tmp2;
        G[a].push_back(tmp);

        tmp2.to = a;
        tmp[0]=tmp2;
        G[b].push_back(tmp);
    }

    seen.assign(n, false);  // 初期化
    int cnt = 0; 
    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            dfs(G, i);
            cnt++; // dfsした回数をカウント
        }
    }
    cout << cnt << endl;

    return 0;
}
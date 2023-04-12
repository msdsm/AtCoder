//辺の定義
//Edge e = {u,v,cost}で初期化宣言可能
struct Edge {
    long long u;
    long long v;
    long long cost;
};

/*辺を直接比較するための関数*/
/*sort(Edge e.begin(),e.end(),comp_e)で重みでソート可能*/
bool comp_e(const Edge &e1, const Edge &e2){return e1.cost < e2.cost;}


struct UnionFind {  // The range of node number is u 0 v n-1
    vector<int> rank, parents;
    UnionFind() {}
    UnionFind(int n) {  // make n trees.
        rank.resize(n, 0);
        parents.resize(n, 0);
        for (int i = 0; i < n; i++) {
            makeTree(i);//最初、iの親はiとする。(iは根)
        }
    }
    void makeTree(int x) {
        parents[x] = x;  // the parent of x is x
        rank[x] = 0;
    }
    bool isSame(int x, int y) { return findRoot(x) == findRoot(y); }
    void unite(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);
        if (rank[x] > rank[y]) {
            parents[y] = x;
        } else {
            parents[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }
    int findRoot(int x) {
        if (x != parents[x]) parents[x] = findRoot(parents[x]);
        return parents[x];
    }
};



/* Kruskal :クラスカル法で minimum spanning tree を求める構造体
    入力: 辺のvector, 頂点数V
    最小全域木の重みの総和: sum
    計算量: O(|E|log|V|)
*/
struct Kruskal {
    UnionFind uft;
    long long sum;  // 最小全域木の重みの総和
    vector<Edge> edges;
    int V;
    Kruskal(const vector<Edge> &edges_, int V_) : edges(edges_), V(V_) { init(); }
    void init() {
        sort(edges.begin(), edges.end(), comp_e); // 辺の重みでソート
        uft = UnionFind(V);
        sum = 0;
        for (auto e : edges) {
            if (!uft.isSame(e.u, e.v)) { // 閉路にならなければ加える
                uft.unite(e.u, e.v);
                sum += e.cost;
            }
        }
    }
};



/* Prim : プリム法で minimum spanning tree を求める構造体
    入力: 隣接行列でのグラフ G
    最小全域木の重みの総和: sum
    計算量: O(|V|^2)
*/
vector<vector<int>> G;  // 隣接行列での表現、辺があるなら重み、ないなら-1
struct Prim {
    const int INF = 1e9;
    int sum;              // MSTの重みの総和
    int n;                // 頂点数
    vector<int> mincost;  // 既に確定した頂点からの最小コスト（確定済みから行けない時は INF）
    vector<bool> used;    // 既に確定したかどうか
    Prim(vector<vector<int>> const& Graph) {
        init(Graph);
    }
    void init(vector<vector<int>> const& Graph) {
        n = (int)Graph.size();
        mincost.assign(n, INF);
        used.assign(n, false);
        sum = 0;
        mincost[0] = 0;  // 始め頂点0からスタートさせる
        while (true) {
            int v = -1;
            for (int u = 0; u < n; u++) {  // コストが最小で行ける頂点 v を探す
                if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
            }
            if (v == -1) break;  // MST ができたので終了
            used[v] = true;
            sum += mincost[v];
            for (int u = 0; u < n; u++) {  // 確定した頂点から行ける頂点について、最小コストを更新
                if (Graph[v][u] != -1) mincost[u] = min(mincost[u], Graph[v][u]);
            }
        }
    }
};
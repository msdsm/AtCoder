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


/* SegTree<X>(n,fx,ex): モノイド(集合X, 二項演算fx, 単位元ex)についてサイズnで構築
    set(int i, X x), build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b): [a,b) 全てにfxを作用させた値を取得。O(log(n))

λ式を使用しているため、コンパイルの際は g++-11 segtree.cpp -o segtree でコンパイルする

*/
template <typename X>
struct SegTree {
    using FX = function<X(X, X)>; // X•X -> X となる関数の型
    int n;
    FX fx;
    const X ex;
    vector<X> dat;
    SegTree(int n_, FX fx_, X ex_) : n(), fx(fx_), ex(ex_), dat(n_ * 4, ex_) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }

    void set(int i, X x) { dat[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }

void update(int i, X x) {
    i += n - 1;
    dat[i] = x;
    while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }

    X query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    X query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return ex;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(vl, vr);
        }
    }
};


int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout<<fixed<<setprecision(20);


    /*RMQ(Range Minimum Query)の場合*/
    int n = 5;
    auto fx = [](int x1,int x2) -> int {return min(x1,x2);};
    int ex = numeric_limits<int>::max();
    SegTree<int> rmq(n,fx,ex);
    vector<int> a(n);
    rep(i,n)a[i]=i;
    rep(i,n){
        rmq.set(i,a[i]);//葉に値セットする
    }
    rmq.build();//葉から根に向かってセグ木構築

    cout << "debug start" << endl;
    rep(i,2*rmq.n-1){
        cout << rmq.dat[i] << endl;
    }
    cout << "debug end" << endl;

    cout << rmq.query(0,5) << endl;
    rmq.update(0,-1);
    cout << rmq.query(0,5) << endl;
    cout << rmq.query(1,3) << endl;
}

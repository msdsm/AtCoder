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


//#pragma once

template <typename T, typename F>
struct SegmentTree2D {
 private:
  ll id(ll h, ll w) { return h * 2 * W + w; }

 public:
  ll H, W;
  vector<T> seg;
  const F f;
  const T I;

  SegmentTree2D(ll h, ll w, F _f, const T& i) : f(_f), I(i) { init(h, w); }

  void init(ll h, ll w) {
    H = W = 1;
    while (H < h) H <<= 1;
    while (W < w) W <<= 1;
    seg.assign(4 * H * W, I);
  }

  // build にのみ呼ぶ
  void set(ll h, ll w, const T& x) { seg[id(h + H, w + W)] = x; }

  void build() {
    // w in [W, 2W)
    for (ll w = W; w < 2 * W; w++) {
      for (ll h = H - 1; h; h--) {
        seg[id(h, w)] = f(seg[id(2 * h + 0, w)], seg[id(2 * h + 1, w)]);
      }
    }
    // h in [0, 2H)
    for (ll h = 0; h < 2 * H; h++) {
      for (ll w = W - 1; w; w--) {
        seg[id(h, w)] = f(seg[id(h, 2 * w + 0)], seg[id(h, 2 * w + 1)]);
      }
    }
  }

  T get(ll h, ll w) const { return seg[id(h + H, w + W)]; }
  T operator()(ll h, ll w) const { return seg[id(h + H, w + W)]; }

  void update(ll h, ll w, const T& x) {
    h += H, w += W;
    seg[id(h, w)] = x;
    for (ll i = h >> 1; i; i >>= 1) {
      seg[id(i, w)] = f(seg[id(2 * i + 0, w)], seg[id(2 * i + 1, w)]);
    }
    for (; h; h >>= 1) {
      for (ll j = w >> 1; j; j >>= 1) {
        seg[id(h, j)] = f(seg[id(h, 2 * j + 0)], seg[id(h, 2 * j + 1)]);
      }
    }
  }

  T _inner_query(ll h, ll w1, ll w2) {
    T res = I;
    for (; w1 < w2; w1 >>= 1, w2 >>= 1) {
      if (w1 & 1) res = f(res, seg[id(h, w1)]), w1++;
      if (w2 & 1) --w2, res = f(res, seg[id(h, w2)]);
    }
    return res;
  }

  // [ (h1,w1), (h2,w2) ) 半開
  T query(ll h1, ll w1, ll h2, ll w2) {
    if (h1 >= h2 || w1 >= w2) return I;
    T res = I;
    h1 += H, h2 += H, w1 += W, w2 += W;
    for (; h1 < h2; h1 >>= 1, h2 >>= 1) {
      if (h1 & 1) res = f(res, _inner_query(h1, w1, w2)), h1++;
      if (h2 & 1) --h2, res = f(res, _inner_query(h2, w1, w2));
    }
    return res;
  }
};

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,q;
	cin >> n >> q;
	vector<ll> a(n),b(n);
	cinf(a,n);
	cinf(b,n);
	ll e = a[0]/GCD(a[0],b[0])*b[0];
	rep(i,n){
		e = a[i]/GCD(a[i],e)*e;
	}
	rep(i,n){
		e = b[i]/GCD(b[i],e)*e;
	}
	function<ll(ll,ll)> f = GCD;
	SegmentTree2D<ll, function<ll(ll,ll)> >s(n,n,f,e);
	rep(i,n){
		rep(j,n){
			s.update(i,j,a[i]+b[j]);
		}
	}
	while(q--){
		ll h1,h2,w1,w2;
		cin >> h1 >> h2 >> w1 >> w2;
		cout << s.query(h1,h2,w1,w2) << endl;
	}
}
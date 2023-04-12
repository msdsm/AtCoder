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

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back(pll(a, ex));
    }

    // 最後に残った数について
    if (N != 1) res.push_back(pll(N, 1));
    return res;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll k;
	cin >> k;
	vector<pll> v = prime_factorize(k);
	/*
	rep(i,v.size()){
		cout << v[i].fst << ':' << v[i].snd << endl;
	}
	*/
	ll ans = 0;
	rep(i,v.size()){
		ll p = v[i].fst;
		ll num = v[i].snd;
		ll idx = 0;
		ll sum = 0;
		while(num>sum){
			idx++;
			ll next = p*idx;
			ll cnt = 0;
			while(true){
				if(next%p==0){
					cnt++;
					next/=p;
				}else{
					break;
				}
			}
			sum += cnt;
		}
		ll tmp = p*idx;
		if(ans<tmp)
			ans = tmp;
	}
	cout << ans << endl;
}
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

/*  make_is_prime(N)
    入力：整数 N
    出力：N までの数字が素数か判定したベクトル（i番目がtrueならiは素数）
    計算量：O(nloglogn)
*/
vector<bool> make_is_prime(int N) {
    vector<bool> prime(N + 1, true);
    if (n >= 0) prime[0] = false;
    if (n >= 1) prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (!prime[i]) continue;
        for (int j = i * i; j <= N; j += i) {
            prime[j] = false;
        }
    }
    return prime;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll k;
	cin >> k;
	// 素数の累乗の約数の最大の値？
	vector<bool> prime(1000010) = make_is_prime(1000010);
	vector<ll> d;
	for(ll i = 1; i*i <= k; i++){
		if(k%i==0){
			d.push_back(i);
			d.push_back(k/i);
		}
	}
	sort(d.begin(),d.end());
	reverse(d.begin(),d.end());
	rep(i,d.size()){
		ll tmp = d[i];
		if(prime[d[i]]){//素数なら解の候補
			ans = tmp;
			break;
		}
	}
}
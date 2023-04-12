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

std::vector<bool> IsPrime;

void sieve(size_t max){
    if(max+1 > IsPrime.size()){     // resizeで要素数が減らないように
        IsPrime.resize(max+1,true); // IsPrimeに必要な要素数を確保
    } 
    IsPrime[0] = false; // 0は素数ではない
    IsPrime[1] = false; // 1は素数ではない

    for(size_t i=2; i*i<=max; ++i) // 0からsqrt(max)まで調べる
        if(IsPrime[i]) // iが素数ならば
            for(size_t j=2; i*j<=max; ++j) // (max以下の)iの倍数は
                IsPrime[i*j] = false;      // 素数ではない
        }

        ll cnt;

        int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
        	ll n;
        	cin >> n;
        	ll tmp;
        	for(ll q = 1; q*q*q <= n; q++){
        		tmp = q;
        	}
        	sieve(tmp);
        	vector<ll> v;
        	rep(i,tmp+1){
        		if(IsPrime[i])
        			v.push_back(i);
        	}
        	ll s = 0;
        	for(s=0;v[s]*v[s]*v[s]*v[s]<=n;s++){
        		;
        	}
	//cout << s << endl;
        	if(s>0){
        		cnt += (v[s-1]-2)*(v[s-1]-1)/2;
        	}
	//cout << cnt << endl;
        	rep2(s,i,v.size()){
        		ll q = v[i];
        		ll num = lower_bound(v.begin(),v.end(),n/(q*q*q)+1)-v.begin();
        		//cout << num << endl;
        		cnt+=num;
        	}
        	cout << cnt << endl;
        }
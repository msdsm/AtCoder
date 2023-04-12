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

        int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
        	ll n,m;
        	cin >> n >> m;
        	vector<ll> a(n);
        	cinf(a,n);
        	sieve(100000);
        	vector<bool> ans(m+1);
        	rep(i,m+1)ans[i]=true;
        	ans[0]=false;
        	set<ll> st;
        	set<ll> p;
        	rep(i,n){
        		vector<ll> v;
        		for(ll j = 1; j*j<=a[i]; j++){
        			if(a[i]%j==0){
        				if(st.count(j)==0){
        					v.push_back(j);
        					st.insert(j);
        				}
        				if(st.count(a[i]/j)==0){
        					v.push_back(a[i]/j);
        					st.insert(a[i]/j);
        				}
        			}
        		}
        		for(auto itr=v.begin();itr!=v.end();itr++){
        			if(IsPrime[*itr]){
        				p.insert(*itr);
        			}
        		}
        	}
        	for(auto itr=p.begin();itr!=p.end();itr++){
        		ll tmp = *itr;
        		if(tmp>m)continue;
        		ans[tmp]=false;
        		for(ll j = 2; tmp*j<=m; j++){
        			ans[tmp*j]=false;
        		}
        	}
        	vector<ll> ans2;
        	rep(i,m+1){
        		if(ans[i])
        			ans2.push_back(i);
        	}
        	cout << ans2.size() << endl;
        	rep(i,ans2.size())cout << ans2[i] << endl;
        }
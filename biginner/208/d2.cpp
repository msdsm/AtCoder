//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

template <typename T>
bool chmin(T &a, const T& b) {
	if (a > b) {
    a = b;  // aをbで更新
    return true;
}
return false;
}

ll INF = LLONG_MAX;
ll ans;

//ワーシャルフロイド法

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	//cout << INF << endl;
	ll n,m;
	cin >> n >> m;
	vector<ll> a(m),b(m),c(m);
	rep(i,m)cin>>a[i]>>b[i]>>c[i];
	ll p[n][n];
	rep(i,n)rep(j,n)p[i][j]=INF;
	rep(i,m)p[a[i]-1][b[i]-1]=c[i];
	rep(i,n)p[i][i]=0;
	/*上のはK={}の時の状況*/

	/*K={1},K={1,2},・・・としていく*/
	rep(k,n){//行ける都市の番号を徐々に増やす
		rep(i,n){
			rep(j,n){
				//chmin(p[i][j],p[i][k]+p[k][j]); overflowする
				if(!(p[i][k]==INF||p[k][j]==INF))
					chmin(p[i][j],p[i][k]+p[k][j]);
				if(p[i][j]!=INF)
					ans+=p[i][j];
				/*cout << "debug start" << endl;
				cout << "k is " << k << endl;
				rep(i,n){
					rep(j,n){
						if(j==n-1)
							cout << p[i][j] << endl;
						else
							cout << p[i][j] << ' ';
					}
				}
				cout << "debug end" << endl;*/
			}
		}
	}
	cout << ans << endl;
	/*
	このときK={1,2,・・・,N}で、p[i][j]はiからjまでの最短経路になっている
	ワーシャルフロイド法は、O(N^3)で全ての都市の組み合わせの最短経路を算出する
	*/
/*
	cout << "debug start" << endl;
	rep(i,n){
		rep(j,n){
			if(j==n-1)
				cout << (p[i][j]) << endl;
			else
				cout << (p[i][j]) << ' ';
		}
	}
	cout << "debug end" << endl;
*/	
	
}
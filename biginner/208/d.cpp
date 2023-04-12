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

// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

using namespace std;

ll inf = LLONG_MAX;
ll sum;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,m;
	cin >> n >> m;
	vector<ll> a(m),b(m),c(m);
	rep(i,m)cin>>a[i]>>b[i]>>c[i];
	ll path[n][n];
	rep(i,n)rep(j,n)path[i][j]=inf;
	rep(i,m)path[a[i]-1][b[i]-1]=c[i];
	rep(i,n)path[i][i]=0;
	ll f[n][n][n+1];
	rep(i,n)rep(j,n)rep(k,n)f[i][j][k]=0;
	rep(i,n){
		rep(j,n){
			f[i][j][0]=path[i][j];
		}
	}
	/*上のk=0とはK={}の状態*/

	rep(k,n){
		rep(i,n){
			rep(j,n){
				//f[i][j][k+1] = min(f[i][j][k],f[i][k+1][k]+f[k+1][j][k]);
				/*上のやつだと第二引数の和で両方infのときにoverflowして負の整数になる*/

				//下のやつだとうまくいかない、なぜ？
				if(f[i][j][k] - f[k][j][k] < f[i][k][k])
					f[i][j][k+1] = f[i][j][k];
				else
					f[i][j][k+1] = f[i][k][k] + f[k][j][k];
				
			}
		}
	}
	/*k=lとは、行ける都市の集合K={1,2,...,l)という状態*/
	rep(i,n){
		rep(j,n){
			rep2(1,k,n+1){
				if(f[i][j][k]!=inf)
					sum += f[i][j][k];
			}
		}
	}
/*
	cout << "debug start" << endl;
	rep(k,n+1){
		cout << "k is " << k << endl;
		rep(i,n){rep(j,n){
		if(j!=n-1)
			cout << f[i][j][k] << ' ';
		else
			cout << f[i][j][k] << endl;
	}}}
	cout << "debug end" << endl;
*/
	
	cout << sum << endl;
}
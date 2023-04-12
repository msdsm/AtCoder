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

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	int n;
	cin >> n;
	char s[n][n];
	char t[n][n];
	rep(i,n)rep(j,n)cin>>s[i][j];
	rep(i,n)rep(j,n)cin>>t[i][j];
	int srmax=0;//max of row
	int srmin=n;//min of row
	int scmax=0;//max of column
	int scmin=n;//min of column
	rep(i,n){
		rep(j,n){
			if(s[i][j]=='#'){
				if(i>srmax)
					srmax=i;
				if(i<srmin)
					srmin=i;
				if(j>scmax)
					scmax=j;
				if(j<scmin)
					scmin=j;
			}
		}
	}
	int trmax=0;//max of row
	int trmin=n;//min of row
	int tcmax=0;//max of column
	int tcmin=n;//min of column
	rep(i,n){
		rep(j,n){
			if(t[i][j]=='#'){
				if(i>trmax)
					trmax=i;
				if(i<trmin)
					trmin=i;
				if(j>tcmax)
					tcmax=j;
				if(j<tcmin)
					tcmin=j;
			}
		}
	}
	int sr = srmax-srmin+1; //row
	int sc = scmax-scmin+1; //column
	int tr = trmax-trmin+1;
	int tc = tcmax-tcmin+1;
	if(sr==tr&&sc==tc){
		
	}
}
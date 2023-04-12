#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int tmp1;
ll tmp2;
ull cnt;
char g[200010][200010];

int main(){
	ull n,q;
	cin >> n >> q;
	rep(i,n-2){
		rep(j,n-2){
			g[i+1][j+1]='B';
		}
	}
	rep(i,n-1){
		g[i][n-1]='W';
	}
	rep(i,n-1){
		g[n-1][i]='W';
	}
	rep(i,q){
		cin >> tmp1 >> tmp2;
		if(tmp1==1){
			g[0][tmp2-1]='W';
			arep(1,j,n-1){
				if(g[j][tmp2-1]=='W')
					break;
				else{
					g[j][tmp2-1]='W';
					cnt++;
				}
			}
		}else{
			g[tmp2-1][0]='W';
			arep(1,j,n-1){
				if(g[tmp2-1][j]=='W')
					break;
				else{
					g[tmp2-1][j]='W';
					cnt++;
				}
			}
		}
	}
	cout << (n-2)*(n-2)-cnt << endl;
}
#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll black;
ll cnt;

int main(){
	ll h,w,k;
	cin >> h >> w >> k;
	char c[h][w];
	rep(i,h){
		rep(j,w){
			cin >> c[i][j];
			if(c[i][j]=='#')
				black++;
		}
	}

	ll tmp;

	rep(bith,1<<h){
		rep(bitw,1<<w){
			tmp=0;
			rep(i,h){
				rep(j,w){
					if(c[i][j]=='#'){
						if(bith&(1<<i))
							tmp++;
						else if(bitw&(1<<j))
							tmp++;
					}
				}
			}
			if(black-tmp==k)
					cnt++;
		}
	}
	cout << cnt << endl;
}
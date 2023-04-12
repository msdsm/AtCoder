#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

bool chart[101][101];
int a[101],x[101],y[101];
int cnt;

int main(){
	int w,h,n;
	cin >> w >> h >> n;
	rep(i,n){
		cin >> x[i] >> y[i] >> a[i];
	}

	rep(i,n){
		switch(a[i]){
			case 1:
			rep(j,x[i]){
				rep(k,h){
					chart[j][k]=true;
				}
			}
			break;
			case 2:
			arep(x[i],j,w){
				rep(k,h+1){
					chart[j][k]=true;
				}
			}
			break;
			case 3:
			rep(j,y[i]){
				rep(k,w){
					chart[k][j]=true;
				}
			}
			break;
			case 4:
			arep(y[i],j,h){
				rep(k,w){
					chart[k][j]=true;
				}
			}
			break;
		}
	}
	rep(i,w){
		rep(j,h){
			if(!chart[i][j])
				cnt++;
		}
	}
	cout << cnt << endl;

	/*for(ll j=h-1;j>=0;j--){
		rep(i,w){
			if(chart[i][j])
				cout << "*";
			else
				cout << "#";
		}
		cout << endl;
	}*/
}
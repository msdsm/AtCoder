#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

bool bl[3][3];

int main(){
	int a[3][3];
	rep(i,3)rep(j,3)cin>>a[i][j];
	int n;
	cin >> n;
	int b[n];
	cinf(b,n);
	rep(i,n){
		rep(j,3){
			rep(k,3){
				if(a[j][k]==b[i])
					bl[j][k]=true;
				if(bl[j][0]&&bl[j][1]&&bl[j][2]){
					cout << "Yes" << endl;
					return 0;
				}
				if(bl[0][k]&&bl[1][k]&&bl[2][k]){
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	if(bl[0][0]&&bl[1][1]&&bl[2][2]||bl[0][2]&&bl[1][1]&&bl[2][0]){
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
}
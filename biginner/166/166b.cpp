#include <iostream>
#define rep(a,i,n) for(int i=(a);i<(n);i++)

using namespace std;

int main(){
	int n,k,count=0;
	cin >> n >> k;
	int d[k];
	int a[k][n];
	rep(0,i,k){
		cin >> d[i];
		rep(0,j,d[i]){
			cin >> a[i][j];
		}
	}

	rep(1,temp,n+1){
		rep(0,i,k){
			rep(0,j,d[i]){
				if(temp == a[i][j]){
					goto Exit;
				}
			}
		}
		count++;
		Exit:
		;
	}
	cout << count << endl;
}
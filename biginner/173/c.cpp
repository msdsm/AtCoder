#include <bits/stdc++.h>
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define cinf(x,n) for(int i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(int i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll cnt;

char c[10][10];
char tmp[10][10];

int count(const char c[10][10],int h,int w){
	int count=0;
	rep(i,h){
		rep(j,w){
			if(c[i][j]=='#')
				count++;
		}
	}
	return count;
}

bool black(const char c[10][10],int h,int w,int k,int bith,int bitw){
	rep(i,h){
		rep(j,w){
			tmp[i][j]=c[i][j];
		}
	}
	rep(i,h){
		rep(j,w){
			if(bith&(1<<i)||bitw&&(1<<j))
				tmp[i][j]='r';
		}
	}
	if(count(tmp,h,w)==k)
		return true;
	return false;
}

int main(){
	int h,k,w;
	cin >> h >> w >> k;
	rep(i,h){
		rep(j,w){
			cin >> c[i][j];
		}
	}

	for(int bith=0;bith<(1<<h);bith++){
		for(int bitw=0;bitw<(1<<w);bitw++){
			if(black(c,h,w,k,bith,bitw))
				cnt++;
		}
	}
	cout << cnt << endl;
}
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

using P = pair<pll, char>;//位置、きた方向

ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};

ll f(char c){
	if(c=='D')
		return 0;
	else if(c=='R')
		return 1;
	else if(c=='U')
		return 2;
	else
		return 3;
}

char invf(ll i){
	if(i==0)
		return 'D';
	else if(i==1)
		return 'R';
	else if(i==2)
		return 'U';
	else
		return 'L';
}


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll h,w;
	cin >> h >> w;
	vector<vector<char> > c(h);
	pll start;
	rep(i,h)c[i].resize(w);
	rep(i,h){
		rep(j,w){
			cin >> c[i][j];
			if(c[i][j]=='S')
				start = pll(i,j);
		}
	}
	queue<P> s;
	vector<vector<bool> > visited(h);
	rep(i,h)visited[i].resize(w,false);

    //初期化 0
	ll x = start.fst+dx[0];
	ll y = start.snd+dy[0];
	if(x>=0&&x<h&&y>=0&&y<w){
		if(c[x][y]=='.'){
			s.push(P(pll(x,y),'D'));
			visited[x][y]=true;
		}
	}

	while(!s.empty()){
		P tmp = s.front();
		s.pop();
		char di = tmp.snd;
		pll pre = tmp.fst;
/*
		cout << "debug start 0" << endl;
		cout << pre.fst << ' ' << pre.snd << endl;
		cout << "debug end" << endl;
*/		
		
		if(pre==start){
			cout << "Yes" << endl;
			return 0;
		}
		if(di!='U'){//D:0
			x = pre.fst+dx[0];
			y = pre.snd+dy[0];
			if(x>=0&&x<h&&y>=0&&y<w){
				if(c[x][y]=='S'){
					cout << "Yes" << endl;
					return 0;
				}
				if(visited[x][y]==false&&c[x][y]=='.'){
					s.push(P(pll(x,y), 'D'));
					visited[x][y]=true;
				}
			}
		}
		if(di!='D'){//U:2
			x = pre.fst+dx[2];
			y = pre.snd+dy[2];
			if(x>=0&&x<h&&y>=0&&y<w){
				if(c[x][y]=='S'){
					cout << "Yes" << endl;
					return 0;
				}
				if(visited[x][y]==false&&c[x][y]=='.'){
					s.push(P(pll(x,y), 'U'));
					visited[x][y]=true;
				}
			}
		}
		if(di!='R'){//L:3の移動
			x = pre.fst+dx[3];
			y = pre.snd+dy[3];
			if(x>=0&&x<h&&y>=0&&y<w){
				if(c[x][y]=='S'){
					cout << "Yes" << endl;
					return 0;
				}
				if(visited[x][y]==false&&c[x][y]=='.'){
					s.push(P(pll(x,y), 'L'));
					visited[x][y]=true;
				}
			}
		}
		if(di!='L'){//R:1
			x = pre.fst+dx[1];
			y = pre.snd+dy[1];
			if(x>=0&&x<h&&y>=0&&y<w){
				if(c[x][y]=='S'){
					cout << "Yes" << endl;
					return 0;
				}
				if(visited[x][y]==false&&c[x][y]=='.'){
					s.push(P(pll(x,y), 'L'));
					visited[x][y]=true;
				}
			}
		}
	}


	//初期化　3
	x = start.fst+dx[3];
	y = start.snd+dy[3];
	if(x>=0&&x<h&&y>=0&&y<w){
		if(c[x][y]=='.'){
			s.push(P(pll(x,y),'L'));
			visited[x][y]=true;
		}
	}

	while(!s.empty()){
		P tmp = s.front();
		s.pop();
		char di = tmp.snd;
		pll pre = tmp.fst;
/*
		cout << "debug start 3" << endl;
		cout << pre.fst << ' ' << pre.snd << endl;
		cout << "debug end" << endl;
*/		
		
		if(pre==start){
			cout << "Yes" << endl;
			return 0;
		}
		if(di!='U'){//D:0
			 x = pre.fst+dx[0];
			 y = pre.snd+dy[0];
			if(x>=0&&x<h&&y>=0&&y<w){
				if(c[x][y]=='S'){
					cout << "Yes" << endl;
					return 0;
				}
				if(visited[x][y]==false&&c[x][y]=='.'){
					s.push(P(pll(x,y), 'D'));
					visited[x][y]=true;
				}
			}
		}
		if(di!='D'){//U:2
			 x = pre.fst+dx[2];
			 y = pre.snd+dy[2];
			if(x>=0&&x<h&&y>=0&&y<w){
				if(c[x][y]=='S'){
					cout << "Yes" << endl;
					return 0;
				}
				if(visited[x][y]==false&&c[x][y]=='.'){
					s.push(P(pll(x,y), 'U'));
					visited[x][y]=true;
				}
			}
		}
		if(di!='R'){//L:3の移動
			 x = pre.fst+dx[3];
			 y = pre.snd+dy[3];
			if(x>=0&&x<h&&y>=0&&y<w){
				if(c[x][y]=='S'){
					cout << "Yes" << endl;
					return 0;
				}
				if(visited[x][y]==false&&c[x][y]=='.'){
					s.push(P(pll(x,y), 'L'));
					visited[x][y]=true;
				}
			}
		}
		if(di!='L'){//R:1
			 x = pre.fst+dx[1];
			 y = pre.snd+dy[1];
			if(x>=0&&x<h&&y>=0&&y<w){
				if(c[x][y]=='S'){
					cout << "Yes" << endl;
					return 0;
				}
				if(visited[x][y]==false&&c[x][y]=='.'){
					s.push(P(pll(x,y), 'L'));
					visited[x][y]=true;
				}
			}
		}
	}


	//初期化 1
	rep(i,h){
		rep(j,w){
			visited[i][j]=false;
		}
	}
	 x = start.fst+dx[1];
	 y = start.snd+dy[1];
	if(x>=0&&x<h&&y>=0&&y<w){
		if(c[x][y]=='.'){
			s.push(P(pll(x,y),'R'));
			visited[x][y]=true;
		}
	}

	while(!s.empty()){
		P tmp = s.front();
		s.pop();
		char di = tmp.snd;
		pll pre = tmp.fst;
/*
		cout << "debug start 1" << endl;
		cout << pre.fst << ' ' << pre.snd << endl;
		cout << "debug end" << endl;
*/		
		
		if(pre==start){
			cout << "Yes" << endl;
			return 0;
		}
		if(di!='U'){//D:0
			 x = pre.fst+dx[0];
			 y = pre.snd+dy[0];
			if(x>=0&&x<h&&y>=0&&y<w){
				if(c[x][y]=='S'){
					cout << "Yes" << endl;
					return 0;
				}
				if(visited[x][y]==false&&c[x][y]=='.'){
					s.push(P(pll(x,y), 'D'));
					visited[x][y]=true;
				}
			}
		}
		if(di!='D'){//U:2
			 x = pre.fst+dx[2];
			 y = pre.snd+dy[2];
			if(x>=0&&x<h&&y>=0&&y<w){
				if(c[x][y]=='S'){
					cout << "Yes" << endl;
					return 0;
				}
				if(visited[x][y]==false&&c[x][y]=='.'){
					s.push(P(pll(x,y), 'U'));
					visited[x][y]=true;
				}
			}
		}
		if(di!='R'){//L:3の移動
			 x = pre.fst+dx[3];
			 y = pre.snd+dy[3];
			if(x>=0&&x<h&&y>=0&&y<w){
				if(c[x][y]=='S'){
					cout << "Yes" << endl;
					return 0;
				}
				if(visited[x][y]==false&&c[x][y]=='.'){
					s.push(P(pll(x,y), 'L'));
					visited[x][y]=true;
				}
			}
		}
		if(di!='L'){//R:1
			 x = pre.fst+dx[1];
			 y = pre.snd+dy[1];
			if(x>=0&&x<h&&y>=0&&y<w){
				if(c[x][y]=='S'){
					cout << "Yes" << endl;
					return 0;
				}
				if(visited[x][y]==false&&c[x][y]=='.'){
					s.push(P(pll(x,y), 'L'));
					visited[x][y]=true;
				}
			}
		}
	}



	//初期化 2
	rep(i,h){
		rep(j,w){
			visited[i][j]=false;
		}
	}
	 x = start.fst+dx[2];
	 y = start.snd+dy[2];
	if(x>=0&&x<h&&y>=0&&y<w){
		if(c[x][y]=='.'){
			s.push(P(pll(x,y),'U'));
			visited[x][y]=true;
		}
	}

	while(!s.empty()){
		P tmp = s.front();
		s.pop();
		char di = tmp.snd;
		pll pre = tmp.fst;
/*
		cout << "debug start 2" << endl;
		cout << pre.fst << ' ' << pre.snd << endl;
		cout << "debug end" << endl;
*/		
		
		if(pre==start){
			cout << "Yes" << endl;
			return 0;
		}
		if(di!='U'){//D:0
			 x = pre.fst+dx[0];
			 y = pre.snd+dy[0];
			if(x>=0&&x<h&&y>=0&&y<w){
				if(c[x][y]=='S'){
					cout << "Yes" << endl;
					return 0;
				}
				if(visited[x][y]==false&&c[x][y]=='.'){
					s.push(P(pll(x,y), 'D'));
					visited[x][y]=true;
				}
			}
		}
		if(di!='D'){//U:2
			 x = pre.fst+dx[2];
			 y = pre.snd+dy[2];
			if(x>=0&&x<h&&y>=0&&y<w){
				if(c[x][y]=='S'){
					cout << "Yes" << endl;
					return 0;
				}
				if(visited[x][y]==false&&c[x][y]=='.'){
					s.push(P(pll(x,y), 'U'));
					visited[x][y]=true;
				}
			}
		}
		if(di!='R'){//L:3の移動
			 x = pre.fst+dx[3];
			 y = pre.snd+dy[3];
			if(x>=0&&x<h&&y>=0&&y<w){
				if(c[x][y]=='S'){
					cout << "Yes" << endl;
					return 0;
				}
				if(visited[x][y]==false&&c[x][y]=='.'){
					s.push(P(pll(x,y), 'L'));
					visited[x][y]=true;
				}
			}
		}
		if(di!='L'){//R:1
			 x = pre.fst+dx[1];
			 y = pre.snd+dy[1];
			if(x>=0&&x<h&&y>=0&&y<w){
				if(c[x][y]=='S'){
					cout << "Yes" << endl;
					return 0;
				}
				if(visited[x][y]==false&&c[x][y]=='.'){
					s.push(P(pll(x,y), 'L'));
					visited[x][y]=true;
				}
			}
		}
	}
	cout << "No" << endl;
}	
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

class node{
public:
	int depth;
	vector<int> v;//残りを昇順
	pair<int,int> p;//そのペア
	ll sum;//現在までの楽しさ

	node(int dd,vector<int> vv,pair<int,int> pp,ll ss){
		depth = dd;
		v = vv;
		p = pp;
		sum = ss;
	}
};

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll max=0;
	int n;
	cin >> n;
	vector<vector<ll> > a(2*n-1);
	rep(i,2*n-1){
		rep(j,2*n-1-i){
			ll tmp;
			cin >> tmp;
			a[i].push_back(tmp);
		}
	}
/*
	cout << "debug start" << endl;
	rep(i,2*n-1){
		rep(j,a[i].size()){
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;
*/

	stack<node> open;
	rep2(1,i,2*n){
		vector<int> v;
		rep2(1,j,2*n){
			if(j==i)
				continue;
			else
				v.push_back(j);
		}
		node tmp(0,v,pii(0,i),a[0][i-1]);
		open.push(tmp);
	}
/*
	cout << "debug start" << endl;
	while(!open.empty()){
		node tmp = open.top();
		open.pop();
		cout << endl;
		cout << tmp.depth << endl;
		rep(i,tmp.v.size())cout << tmp.v[i] << ' ';
		cout << endl;
		cout << tmp.p.fst << ' ' << tmp.p.snd << endl;
		cout << tmp.sum << endl;
	}

	cout << "debug end" << endl;
*/
	
	while(!open.empty()){
		node tmp = open.top();
		open.pop();
		if(tmp.depth==n-1){
			if(tmp.sum>max)
				max=tmp.sum;
		}else{
			rep2(1,i,tmp.v.size()){
				vector<int> v = tmp.v;
				v.erase(lower_bound(v.begin(),v.end(),v[i]));
				v.erase(lower_bound(v.begin(),v.end(),v[0]));
				/*
				cout << "あいうえ " << tmp.sum << endl;
				cout << a[tmp.v[0]][tmp.v[i]] << endl;
				cout << (tmp.sum ^ a[tmp.v[0]][tmp.v[i]]) << endl;
				*/
				node next(tmp.depth+1,v,pii(tmp.v[0],tmp.v[i]),(tmp.sum ^ a[tmp.v[0]][tmp.v[i]-1-tmp.v[0]]));
/*
				cout << "debug start" << endl;
				cout << "debug start" << endl;
				cout << next.depth << endl;
				rep(i,next.v.size())cout << next.v[i] << ' ';
				cout << endl;
				cout << next.p.fst << ' ' << next.p.snd << endl;
				cout << next.sum << endl;
				cout << "debug end" << endl;	
				cout << "debug end" << endl;
*/				
				
				open.push(next);		
			}
		}
	}
	cout << max << endl;
}
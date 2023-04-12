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
	queue<ll> q;
	priority_queue<ll,vector<ll>,greater<ll> > pq;
	ll Q;
	cin >> Q;
	rep(i,Q){
		int a;
		cin >> a;
		if(a==1){
			ll x;
			cin >> x;
			q.push(x);
		}else if(a==2){
			if(pq.empty()){
				cout << q.front() << endl;
				q.pop();
			}else{
				cout << pq.top() << endl;
				pq.pop();
			}
		}else{
			while(!q.empty()){
				pq.push(q.front());
				q.pop();
			}
		}
	}
}
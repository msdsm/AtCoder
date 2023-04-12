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
	ll n,q;
	cin >> n >> q;
	vector<ll> front(n);
	vector<ll> back(n);
	int t;
	rep(i,q){
		cin >> t;
		if(t==1){
			int x,y;
			cin >> x >> y;
			front[y-1]=x;
			back[x-1]=y;
		}
		if(t==2){
			int x,y;
			cin >> x >> y;
			front[y-1]=0;
			back[x-1]=0;
		}
		if(t==3){
			int x;
			cin >> x;
			stack<ll> s;
			s.push(x);
			vector<ll> ans;
			while(true){
				if(front[s.top()-1]==0)
					break;
				else
					s.push(front[s.top()-1]);
			}
			while(!s.empty()){
				ans.push_back(s.top());
				s.pop();
			}
			ll tmp = x;
			while(true){
				if(back[tmp-1]==0)
					break;
				else{
					ans.push_back(back[tmp-1]);
					tmp = back[tmp-1];
				}
			}
			cout << ans.size() << ' ';
			rep(i,ans.size()){
				if(i!=ans.size()-1)
					cout << ans[i] << ' ';
				else
					cout << ans[i] << endl;
			}
		}
	}
}
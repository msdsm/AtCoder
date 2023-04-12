//ABC247E


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
	ll n,x,y;
	cin >> n >> x >> y;
	vector<ll> a(n);
	cinf(a,n);
	vector<vector<ll> > b;
	vector<ll> tmp;
	rep(i,n){
		if(a[i]<=x && a[i]>=y){
			tmp.push_back(a[i]);
		}else{
			if(!tmp.empty()){
				b.push_back(tmp);
				tmp.clear();
			}
		}
	}
	if(!tmp.empty())
		b.push_back(tmp);
	tmp.clear();

/*
	cout << "debug start b" << endl;
	rep(i,b.size()){
		rep(j,b[i].size()){
			cout << b[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "debug end" << endl;
*/
	ll cnt = 0;
	rep(i,b.size()){
		ll inx = 0;
		ll iny = 0;
		bool end = false;
		ll l = 0;
		ll r = 0;
		if(b[i][0]==x)
			inx++;
		if(b[i][0]==y)
			iny++;
		while(l<b[i].size()){
			while(!(inx>0&&iny>0)){
				r++;
				if(r>=b[i].size()){
					end = true;
					break;
				}
				if(b[i][r]==x)
				inx++;
				if(b[i][r]==y)
				iny++;
			}
			if(end){
				break;
			}
			cnt += b[i].size()-r;
/*
			cout << "debug start" << endl;
			cout << "(" << l << ", " << r << ')' << endl;
			cout << b[i].size()-r << endl;
			cout << inx << endl;
			cout << "debug end" << endl;
*/			
			if(l==r){
				r++;
				if(b[i][r]==x)
					inx++;
				if(b[i][r]==y)
					iny++;
			}
			l++;
			if(l>=b[i].size()){
				break;
			}
			if(b[i][l-1]==x)
				inx--;
			if(b[i][l-1]==y)
				iny--;
		}
	}
	cout << cnt << endl;
}
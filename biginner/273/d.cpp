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
	ll h,w,rs,cs;
	cin >> h >> w >> rs >> cs;
	ll n;
	cin >> n;
	vector<pll> p1(n);
	pcin(p1,n);
	vector<pll> p2(n);
	rep(i,n){
		p2[i].fst = p1[i].snd;
		p2[i].snd = p1[i].fst;
	}
	sort(p1.begin(),p1.end());//行同じ
	sort(p2.begin(),p2.end());//列同じ (列、行)

	vector<pll> p3(n),p4(n);
	rep(i,n){
		p3[i] = pll(-p1[i].fst, -p1[i].snd);
		p4[i] = pll(-p2[i].fst, -p2[i].snd);
	}
	sort(p3.begin(),p3.end());
	sort(p4.begin(),p4.end());

	ll Q;
	cin >> Q;
	while(Q--){
		char d;
		ll l;
		cin >> d >> l;
		if(d=='R'){
			ll idx = lower_bound(p1.begin(),p1.end(),pll(rs,cs))-p1.begin();
			if(idx!=n && rs==p1[idx].fst){
				cs = min(cs+l, p1[idx].snd-1);
			}else{//それ以上右に障害物なし
				cs = min(cs+l, w);
			}
		}else if(d=='L'){
			ll idx = lower_bound(p3.begin(),p3.end(),pll(-rs,-cs))-p3.begin();
			if(idx!=n &&rs==-p3[idx].fst){
				cs = max(cs-l, -p3[idx].snd+1);
			}else{//それ以上左に障害物なし
				cs = max(cs-l, (ll)1);
			}
		}else if(d=='U'){//おかしい？
			ll idx = lower_bound(p4.begin(),p4.end(),pll(-cs,-rs))-p4.begin();
/*
			cout << "debug start" << endl;
			cout << idx << endl;
			cout << -p4[idx].fst << endl;
			cout << -p4[idx].snd << endl;
			cout << -rs << ' ' << -cs << endl;
			cout << "debug end" << endl;

			cout << "debug start" << endl;
			rep(i,n){
				cout << p4[i].fst << ' ' << p4[i].snd << endl;
			}
			cout << "debug end" << endl;
*/			
			
			
			
			if(idx!=n && cs==-p4[idx].fst){
				rs = max(rs-l, -p4[idx].snd+1);
			}else{//それ以上下に障害物なし
				rs = max(rs-l, (ll)1);
			}
		}else{//下
			ll idx = lower_bound(p2.begin(),p2.end(),pll(cs,rs))-p2.begin();
			if(idx!=n && cs==p2[idx].fst){
				rs = min(rs+l, p2[idx].snd-1);
			}else{//それ以上下に障害物なし
				rs = min(rs+l, h);
			}
		}
		cout << rs << ' ' << cs << endl;
	}
}
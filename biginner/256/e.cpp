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

using P = pair<ll,pll>;//cost,きらい,index

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	vector<ll> x(n),c(n);
	cinf(x,n);
	rep(i,n)x[i]--;
	cinf(c,n);
	vector<P> v(n);
	rep(i,n){
		v[i] = P(c[i],pll(x[i],i));
	}
	sort(v.begin(),v.end(),greater<P>());
	//cout << v[0].fst << endl;
	vector<bool> bl(n,false);
	vector<ll> p;
	ll ans = 0;
	rep(i,n){		
		ll left = v[i].snd.snd;
		ll right = v[i].snd.fst;
		cout << "debug start" << endl;
		cout << i << endl;
		cout << left << endl;
		cout << right << endl;
		cout << "debug end" << endl;
		if(!bl[left]&&!bl[right]){
			p.push_back(left);
			p.push_back(right);
			bl[left]=true;
			bl[right]=true;
		}else if(bl[left]&&bl[right]){
			ll inl = lower_bound(p.begin(),p.end(),left)-p.begin();
			ll inr = lower_bound(p.begin(),p.end(),right)-p.begin();

			cout << "debug start" << endl;
			cout << inl << endl;
			cout << inr << endl;
			rep(i,p.size())cout<<p[i]<<' ';cout<<endl;
			cout << "debug end" << endl;

			
			
			if(inr < inl)
				ans += v[i].fst;
		}else if(bl[left]&&!bl[right]){
			bl[right]=true;
			auto itr = lower_bound(p.begin(),p.end(),left);
			itr++;
			if(itr==p.end()){
				p.push_back(right);
				continue;
			}
			p.insert(itr,right);
		}else{
			bl[left]=true;
			auto itr = lower_bound(p.begin(),p.end(),right);
			if(itr==p.begin()){
				reverse(p.begin(),p.end());
				p.push_back(left);
				reverse(p.begin(),p.end());
				continue;
			}
			itr--;
			p.insert(itr,left);
		}
	}
	cout << ans << endl;
}
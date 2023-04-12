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
	vector<ll> p(n);//順列
	vector<ll> in(n);//index iが何番目にあるか
	vector<ll> list(n,-100);
	vector<ll> listr(n,-100);
	ll start = v[0].snd.snd;
	ll end = -1;
	ll ans = 0;
	rep(i,n){		
		ll left = v[i].snd.snd;
		ll right = v[i].snd.fst;
/*
		cout << "debug start" << endl;
		cout << "i:" << i << endl;
		cout << "start:" << start << endl;
		cout << "end:" << end << endl;
		rep(i,n)cout << list[i] << ' ';cout << endl;
		cout << "debug end" << endl;
*/		
		
		if(!bl[left]&&!bl[right]){
			if(end==-1){
				list[left] = right;
				listr[left] = -1;
				listr[right] = left;
				list[right] = -1;
				end = right;
				start = left;
			}else{
				list[end]=left;
				list[left]=right;
				list[right]=-1;
				listr[left]=end;
				listr[right]=left;
				end = right;
			}
			bl[left]=true;
			bl[right]=true;
		}else if(bl[left]&&bl[right]){
			continue;
		}else if(bl[left]&&!bl[right]){
			bl[right]=true;
			if(list[left]==-1){
				list[left] = right;
				list[right] = -1;
				listr[right] = left;
				end = right;
			}else{
				ll tmp = list[left];
				list[left] = right;
				list[right] = tmp;
				listr[tmp] = right;
				listr[right] = left;
			}
		}else{
			bl[left]=true;
			if(listr[right]==-1){
				list[left]=right;
				listr[right]=left;
				listr[left]=-1;
				start = left;
			}else{
				ll tmp = listr[right];
				list[tmp]=left;
				list[left]=right;
				listr[right]=left;
				listr[left]=tmp;
			}
		}
	}
	p[0]=start;
/*
	cout << "debug start" << endl;
	cout << start << endl;cout<<endl;
	rep(i,n){
		cout << list[i] << endl;
	}
	cout << "debug end" << endl;
*/	
	rep2(1,i,n){
		p[i] = list[p[i-1]];
	}
	/*
	cout << "debug start p" << endl;
	rep(i,n){
		cout << p[i] << endl;
	}
	cout << "debug end" << endl;*/
	rep(i,n)in[p[i]]=i;
	rep(i,n){
		if(in[i]>in[x[i]])
			ans += c[i];
	}
	cout << ans << endl;
}
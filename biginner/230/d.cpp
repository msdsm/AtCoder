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

ll cnt;

/*pairの自作比較関数...secondの値について昇順*/
bool compare_by_second(pair<long long int,long long int> a,pair<long long int,long long int> b){
  if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

bool f(ll x,ll l,ll r){
	if(x<=r && x>=l)
		return true;
	return false;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n,d;
	cin >> n >> d;
	vector<pll> p(n);
	pcin(p,n);
	sort(p.begin(),p.end(),compare_by_second);
	/*
	rep(i,n){
		cout << p[i].fst << ' ' << p[i].snd << endl;
	}
	*/
	rep(i,n){
		cnt++;
		ll tmp = p[i].snd;
		while(true){
			if(i<n-1&&tmp+d-1>=p[i+1].fst&&tmp<=p[i+1].snd){
				i++;
			}else{
				break;
			}
		}
	}
	cout << cnt << endl;
}
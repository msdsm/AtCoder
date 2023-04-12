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

ll ans;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll l,n1,n2;
	cin >> l >> n1 >> n2;
	vector<pll> v1(n1),v2(n2);
	pcin(v1,n1);
	pcin(v2,n2);
	vector<ll> in1(n1),in2(n2);
	in1[0]=0;
	rep2(1,i,n1){
		in1[i] = in1[i-1]+v1[i-1].snd;
	}
	in2[0]=0;
	rep2(1,i,n2){
		in2[i] = in2[i-1]+v2[i-1].snd;
	}
	ll idx = 0;
	while(idx<l){
		ll id1 = upper_bound(in1.begin(),in1.end(),idx)-in1.begin();
		ll id2 = upper_bound(in2.begin(),in2.end(),idx)-in2.begin();
		id1--;
		id2--;
		if(v1[id1].fst==v2[id2].fst){
			ans += min(in1[id1]+v1[id1].snd-idx, in2[id2]+v2[id2].snd-idx);
			idx += min(in1[id1]+v1[id1].snd-idx, in2[id2]+v2[id2].snd-idx);
		}else{
			idx += min(in1[id1]+v1[id1].snd-idx, in2[id2]+v2[id2].snd-idx);
		}
	}
	cout << ans << endl;
}
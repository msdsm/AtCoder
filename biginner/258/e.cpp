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
	ll n,q,x;
	cin >> n >> q >> x;
	vector<ll> w(n);
	cinf(w,n);
	vector<ll> s(n);
	s[0]=w[0];
	rep2(1,i,n){
		s[i] = s[i-1]+w[i];
	}
	vector<bool> used(n,false);
	vector<ll> indices(n,-1);//wのindexが箱の何番目?
	ll index=0;
	ll xxx = x;
	x %= s[n-1];
	ll start;
	ll end;
	ll T;//周期数
	rep(i,n+1){//周期出す
		//cout << index << endl;
		if(used[index]){
			start = indices[index];
			end = i-1;
			T = end - start + 1;
			break;
		}else{
			used[index]=true;
			indices[index]=i;
		}

		ll tmp;
		if(index>0){
			if(s[n-1]-s[index-1]>=x)
				tmp = lower_bound(s.begin()+index, s.end(), x+s[index-1])-s.begin();
			else{
				tmp = lower_bound(s.begin(), s.end(), x-(s[n-1]-s[index-1]))-s.begin();
			}
		}
		else
			tmp = lower_bound(s.begin(),s.end(),x)-s.begin();
		//w[l:r]=w[index,tmp]>=x
		tmp++;
		tmp%=n;
		index = tmp;//次のl
	}

	vector<ll> sv(start);
	vector<ll> tv(T);
	x = xxx;
	index = 0;
	rep(i,start){//周期前のこたえ　
		x = xxx;
		ll tmp = 0;
		ll tmp2;
		if(x>s[n-1]){
			tmp += x/s[n-1]*n;
			x%=s[n-1];
		}
		if(x==0){
			tmp2 = index-1;
			if(tmp2==-1)
				tmp2 = n-1;
		}else if(index>0){
			if(s[n-1]-s[index-1]>=x){
				tmp2 = lower_bound(s.begin()+index, s.end(), x+s[index-1])-s.begin();
				tmp += tmp2-index+1;
			}else{
				tmp2 = lower_bound(s.begin(), s.end(), x-(s[n-1]-s[index-1]))-s.begin();
				tmp += n-index;
				tmp += tmp2+1;
			}
		}else{
			tmp2 = lower_bound(s.begin(),s.end(),x)-s.begin();
			tmp += tmp2+1;
		}
		sv[i]=tmp;
		//w[l:r]=w[index,tmp2]>=x
		tmp2++;
		tmp2%=n;
		index = tmp2;
	}

	rep(i,T){//周期入ってからの答え
		x = xxx;
		ll tmp = 0;
		ll tmp2;
		//cout << index << endl;
		if(x>s[n-1]){
			tmp += x/s[n-1]*n;
			x%=s[n-1];
		}
		if(x==0){
			tmp2 = (index-1+n)%n;
		}else if(index>0){
			if(s[n-1]-s[index-1]>=x){
				tmp2 = lower_bound(s.begin()+index, s.end(), x+s[index-1])-s.begin();
				tmp += tmp2-index+1;
			}else{
				tmp2 = lower_bound(s.begin(), s.end(), x-(s[n-1]-s[index-1]))-s.begin();
				tmp += n-index;
				tmp += tmp2+1;
			}
		}else{
			tmp2 = lower_bound(s.begin(),s.end(),x)-s.begin();
			tmp += tmp2+1;
		}
		tv[i]=tmp;
		//w[l:r]=w[index,tmp2]>=x
		tmp2++;
		tmp2%=n;
		index = tmp2;
	}

/*
	cout << "debug start" << endl;
	cout << start << endl;
	cout << end << endl;
	cout << T << endl;
	rep(i,start)cout<< sv[i] << ' ';
	cout<<endl;
	rep(i,T)cout << tv[i] << ' ';
	cout<<endl;
	cout << "debug end" << endl;
*/	
	

	while(q--){
		ll k;
		cin >> k;
		k--;
		if(k<start)
			cout << sv[k] << endl;
		else
			cout << tv[(k-start)%T] << endl;
	}
}
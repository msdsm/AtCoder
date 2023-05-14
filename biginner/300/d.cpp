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

std::vector<ll> Eratosthenes( const ll N )
{
    std::vector<bool> is_prime( N + 1 );
    for( ll i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;
    }
    std::vector<ll> P;
    for( ll i = 2; i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( ll j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
            P.push_back( i );
        }
    }
    return P;
}

ll ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout<<fixed<<setprecision(20);
	ll n;
	cin >> n;
	ll m;
	for(ll i=1;i*i<=n;i++){
		m = i;
	}
	vector<ll> v = Eratosthenes(m);
	ll ax,bx,cx;
	bool fla=true;
	bool flb=true;
	bool flc=true;
	rep(i,v.size()){
		if(fla)ax=i;
		if(flb)bx=i;
		if(flc)cx=i;
		ll tmp = v[i]*v[i];
		if(tmp>=n)
			flc=false;
		ll tmp2 = tmp*v[i];
		if(tmp2>=n)
			flb=false;
		ll tmp3 = tmp*tmp2;
		if(tmp3>=n)
			fla=false;
	}
	rep(i,ax){
		ll a = v[i];
		rep2(i+1,j,bx){
			ll b = v[j];
			if(a*a*b*b*b>=n)
				break;
			rep2(j+1,k,cx){
				ll c = v[k];
				if(a*a*b*c*c>n)
					break;
				ans++;
			}
		}
	}
	cout << ans << endl;
/*
	cout << "debug start" << endl;
	rep(i,v.size())cout<<v[i]<< ' ';
	cout<<endl;
	cout << "debug end" << endl;
*/

}
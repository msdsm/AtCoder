#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

string tmp;

/*二分探索　O(log n) */
const int KEY_NOT_FOUND = -1;
int binary_search(vector<string> ary,string key,int imin,int imax){
  if(imin > imax)
    return KEY_NOT_FOUND;
  else{
    int imid = imin + (imax-imin)/2;
    if(ary[imid] > key)
      return binary_search(ary,key,imin,imid-1);
    else if(ary[imid] < key)
      return binary_search(ary,key,imid+1,imax);
    else
      return imid;
  }
}

int main(){
	ll n;
	cin >> n;
	vector<string> s(n),t(n);
	rep(i,n){
		cin >> tmp;
		if(tmp[i]=="!")
			t.insert(tmp);
		else
			s.insert(tmp);
	}
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	rep(i,s.size()){
		if(binary_search(t,s[i],t.begin(),t.end())==KEY_NOT_FOUND){
			cout << s[i] << endl;
			exit(0);
		}
	}
	cout << "satisfiable" << endl;
}
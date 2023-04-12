#include <iostream>
#define rep(a,i,n) for(int i=(a);i<(n);i++)

using namespace std;

int main(){
	long long x,count=0,sum=100;
	cin >> x;
	while(sum < x){
		sum += sum/100;
		count++;
	}
	cout << count << endl;
}
#include <iostream>
#include <iomanip>
typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
	ld n;
	cin >> n;
	cout << setprecision(10) << static_cast<ld>((n/3.0)*(n/3.0)*(n/3.0)) << endl;
}
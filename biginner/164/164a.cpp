#include <iostream>

using namespace std;

int main(){
	int s,w;
	cin >> s;
	cin >> w;
	if(s<=w)
		cout << "unsafe" << endl;
	else
		cout << "safe" << endl;
}
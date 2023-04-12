#include <iostream>

using namespace std;

int main(){
	int x;
	cin >> x;
	int y = 1000*(x/500) + 5*((x%500)/5);
	cout << y << endl;
}
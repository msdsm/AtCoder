/*
剰余群における逆元計算
*/

#include <iostream>

using namespace std;


// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}



int main(){
	const int MOD = 1000000007;
	long long a = 12345678900000;
	long long b = 100000;
	cout << (a/b)%MOD << endl;//確認用
	
	a %= MOD;
	cout << a * modinv(b, MOD) % MOD << endl;
}
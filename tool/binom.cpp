/*nCr 高速*/
/*使い方
下の変数、関数2つをmain関数外に貼る
main関数内で一番最初にbinom_init()を呼び出しセットする
nCrを使いたい時にbinom(n,r)で参照可能
/*ここから*/
vector<ll> fac,finv,inv;
void binom_init() {
    fac.resize(MAX);
    finv.resize(MAX);
    inv.resize(MAX);
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for(int i=2; i<MAX; i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD-MOD/i*inv[MOD%i]%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}
ll binom(ll n, ll r){
    if(n<r || n<0 || r<0) return 0;
    return fac[n]*finv[r]%MOD*finv[n-r]%MOD;
}
/*ここまでをmain関数外に貼り付ける*/
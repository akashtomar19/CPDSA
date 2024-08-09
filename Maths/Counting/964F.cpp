#include <bits/stdc++.h>
using namespace std;


const int N = 2e5 + 5, mod = 1e9 + 7;
int64_t fact[N];
int64_t pw(int64_t a, int64_t b) {
	int64_t r = 1;
	while(b > 0) {
		if(b & 1) r = (r * a) % mod;
		b /= 2;
		a = (a * a) % mod;
	}
	return r;
}
int64_t C(int64_t n, int64_t k) {
	if(n < k) return 0LL;
	return (fact[n] * pw((fact[n - k] * fact[k]) % mod, mod - 2)) % mod;
}
int main(){
    #define int long long
    fact[0] = 1;
	for(int64_t i = 1; i < N; ++i) fact[i] = (fact[i - 1] * i) % mod;
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        int x;
        int ones = 0;
        for(int i = 0;i < n; i++){
            cin>>x;
            ones += x;
        }
        int res = 0;
        for(int i = k / 2 + 1; i <= min(ones, k); i++){
            res += C(ones, i) % mod * C(n - ones, k - i) % mod;
            res %= mod;
        }
        cout<<res<<endl;
	}
}

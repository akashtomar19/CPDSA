#include<bits/stdc++.h>
using namespace std;
#define int long long

int mod = 998244353;

long long modpow(long long a, long long b, int mod) {
    long long res = 1;
    while(b > 0) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int32_t main(){
    int t = 1;
    while(t--){
        int n;
        cin>>n;
        /**
            from b = 2 to n summation(n - b + 1 - (n / b))
            n = n * (n - 1)
            1 = (n - 1)
            b = n*(n + 1) / 2 - 1
            = n * (n - 1) + (n - 1) - (n * (n + 1) / 2 - 1)
            = (n + 1) * (n - 1) - n * (n + 1) / 2 + 1
            = (n + 1)((n - 1) - n / 2) + 1
            = (n + 1)((2n - 2) - n)/2 + 1
            = (n + 1)(n - 2) / 2 + 1
            = ((n + 1)(n - 2) + 2) / 2
            = (n * (n - 2) + n) / 2
            = n(n - 2 + 1) / 2
            = n(n - 1)/2



        **///

        int res = (n % mod) * ((n - 1 + mod) % mod) % mod * (modpow(2, mod - 2, mod)) % mod ;
        int sub = 0;

        for(int i = 2; i <= n;){
            int v = n / i;
            int nextv = n / v;
            int f = (nextv - i + 1) % mod;
            i = nextv + 1;
            sub += f * (v % mod) ;
            sub %= mod;
        }
        res -= sub;
        res += mod;
        res %= mod;
        cout<<res<<endl;
    }
}

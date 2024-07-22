// https://codeforces.com/contest/1983/problem/E
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
struct Mint {
    int val;

    Mint(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
        if (v >= MOD)
            v %= MOD;
        val = v;
    }

    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
        return x < 0 ? x + m : x;
    }
    explicit operator int() const {
        return val;
    }
    Mint& operator+=(const Mint &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    Mint& operator-=(const Mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
    Mint& operator*=(const Mint &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
    Mint& operator/=(const Mint &other) {
        return *this *= other.inv();
    }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    Mint& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
    Mint& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
    // friend Mint operator<=(const Mint &a, const Mint &b) { return (int)a <= (int)b; }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const {
        return mod_inv(val);
    }
    Mint power(long long p) const {
        assert(p >= 0);
        Mint a = *this, result = 1;
        while (p > 0) {
            if (p & 1)
                result *= a;

            a *= a;
            p >>= 1;
        }
        return result;
    }
    friend ostream& operator << (ostream &stream, const Mint &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, Mint &m) {
        return stream>>m.val;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        Mint n, k;
        cin>>n>>k;
        Mint ksum = 0, nsum = 0;
        for(int i = 0; i < (int)k; i++){
            int x;
            cin>>x;
            ksum += x;
        }
        for(int i = (int)k; i < (int)n; i++){
            int x;
            cin>>x;
            nsum += x;
        }
        Mint c = ceil((1.0 * (int)n - (int)k + 1) /2);
        Mint d = floor((1.0 * (int)n - (int)k + 1) / 2);

        Mint a = ceil((1.0 * (int)n - (int)k) / 2);
        Mint b = floor((1.0 * (int)n - (int)k) / 2);
        //cout<<a<<b<<endl;
        //cout<<c<<d<<endl;

        auto alice = a/(a + b) * nsum + c/(c + d) * ksum;
        auto bob = b / (a + b) * nsum + d/(c + d) * ksum;
        cout<<alice<<" "<<bob<<endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e18
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define int long long
const int mod = 1e9 + 7;

vector<int> fact;
vector<int> invf;

int inv(int a) {
  return a <= 1 ? a : mod - (mod/a) * inv(mod % a) % mod;
}

int combi(int n, int r) {
    if(r == 0) return 1;
    if(r > n || n < 0 || r < 0) return 0;
    return (fact[n] * invf[r] % mod) * invf[n-r] % mod;
}
void solve() {
    int n;
    cin>>n;
    int res = 0;
    //int mod = 1e9 + 7;

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= 2 * i + 1; j++){
            int a = combi(min(j - 1, n), j - (i + 1));
            int b = combi(n - j, i - (j - (i + 1)));
            int c = a * b % mod * j % mod;
            res += c;
            res %= mod;

        }
    }
    res += 1;
    res %= mod;
    cout<<res<<endl;
}


int32_t main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    fact = vector<int>(10003, 1);
    invf = vector<int>(10003);

    invf[0] = inv(fact[0]);

    for(int i = 1; i <= 10002; i++) {
        fact[i] = (fact[i-1] * i) % mod;
        invf[i] = inv(fact[i]);
    }
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        //cout << "Case #" << i << ": ";
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define int long long
using namespace std;

const int mod = 1e9 + 7;

vector<int> fact;
vector<int> invf;

int inv(int a) {
    int m = mod, m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    // Apply extended Euclid Algorithm
    while (a > 1) {
        // q is quotient
        q = a / m;
        t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

int combi(int n, int r) {
    if (r == 0) return 1;
    if (r > n || n < 0 || r < 0) return 0;
    return (fact[n] * invf[r] % mod) * invf[n - r] % mod;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact = vector<int>(200006, 1);
    invf = vector<int>(200006);

    for (int i = 1; i <= 200005; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    for (int i = 0; i <= 200005; i++) {
        invf[i] = inv(fact[i]);
    }

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1);
        unordered_map<int, int> mm;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mm[a[i]]++;
        }
        vector<pair<int, int>> v;
        for (auto p : mm) {
            v.push_back({p.first, p.second});
        }
        sort(v.begin(), v.end());
        int j = 0;
        int res = 0;
        //cout<<fact[1] * invf[1]<<endl;
        int cur = 1;
        for (int i = 0; i < v.size(); i++) {
            cur *= v[i].second % mod;
            cur %= mod;

            while (1ll * v[i].first - 1ll * v[j].first >= 1ll * m) {
                cur *= inv(v[j].second);
                cur %= mod;
                j++;
            }

            if (i - j + 1 != m) continue;
            res += cur;
            res %= mod;
        }
        cout << res << endl;
    }
}

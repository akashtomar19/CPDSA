#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
vector<bool> is_prime(1e6, true);


void solve() {
    int n, x;
    cin>>n>>x;
    int res = 0;
    for(int a = 1; a <= n; a++){
        for(int b = 1; b <= n/a; b++){
            int f = (n - a*b) / (a + b);
            int s = (x - a - b);
            int mx = min(f, s);
            res += max(0, mx);
        }
    }
    cout<<res<<endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;



    while (t--) {
        solve();
    }

    return 0;
}

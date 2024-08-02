#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <random>
#include <algorithm>
#include<functional>

using namespace std;

#include<iostream>
#define int long long
using namespace std;
vector<vector<int>>dp;

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>>gp(n + 1);
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            gp[u].push_back(v);
            gp[v].push_back(u);
        }
        vector<int>height(n + 1, 0), vis(n + 1, 0);
        vector<int>szs(n + 1, 1), dp(n + 1, 1e9);
        vector<int>cand;
        function<void(int, int, int)> dfs = [&](int u, int h, int par) {
            vis[u] = 1;
            height[u] = h;
            for (int v : gp[u]) {
                if (!vis[v]) {
                    dfs(v, h + 1, u);
                    szs[u] += szs[v];
                    dp[u] = min(dp[u], dp[v]);
                }

            }
            for(int v: gp[u]){
                if(v == par)continue;
                dp[u] = min(dp[u], height[v]);
            }
            if (dp[u] >= h) {
                cand.push_back(u);
            }
        };
        dfs(1, 1, -1);
        int res = 1e16;
        for (auto c : cand) {

            int s1 = szs[c];
            int s2 = n - szs[c];
            int tot = n * (n - 1) / 2;
            int gone = s1 * s2;
            res = min(tot - gone, res);
        }
        cout << (res == 1e16 ? 0 : res) << endl;
    }
}

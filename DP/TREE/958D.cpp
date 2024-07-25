#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n + 1];
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        vector<vector<int>>gp(n + 1);
        for(int i = 1; i <= n - 1; i++){
            int u, v;
            cin>>u>>v;
            gp[u].push_back(v);
            gp[v].push_back(u);
        }
        vector<vector<int>>dp(n + 1, vector<int>(31, 1e18));
        vector<vector<int>>mnn(n + 1, vector<int>(2, 0));
        function<void(int, int)>dfs = [&](int u, int par){
            for(int v: gp[u]){
                if(v == par)continue;
                dfs(v, u);
            }
            for(int i = 1; i <= 30; i++){
                dp[u][i] = 0;
                for(int v: gp[u]){
                    if(v == par)continue;
                    int mn = 1e18;
                    dp[u][i] += ((i == mnn[v][0]) ? dp[v][mnn[v][1]] : dp[v][mnn[v][0]]);
                }
                dp[u][i] += i * a[u];
            }
            for(int i = 1; i <= 30; i++){
                if((!mnn[u][0]) || (dp[u][i] < dp[u][mnn[u][0]])){
                    mnn[u][1] = mnn[u][0];
                    mnn[u][0] = i;
                } else if((!mnn[u][1]) || dp[u][mnn[u][1]] > dp[u][i]){
                    mnn[u][1] = i;
                }
            }
        };

        dfs(1, -1);
        int res = 1e18;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 30; j++){
                res = min(res, dp[1][j]);
            }
        }
        cout<<res<<endl;
    }
}

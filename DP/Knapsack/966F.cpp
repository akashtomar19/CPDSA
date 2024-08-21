
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int kk = k;
        int a[n + 1][2];
        for(int i = 1; i <= n; i++){
            cin>>a[i][0]>>a[i][1];
        }
        vector<vector<int>>cost(n + 1, vector<int>(201, 1e9 + 2));
        vector<vector<int>>dp(n + 1, vector<int>(201, 1e9 + 2));
        for(auto k = 1; k <= n; k++){
            int x = a[k][0], y = a[k][1];
            for(int i = 0; i <= x; i++){
                for(int j = 0; j <= y; j++){
                    int cur = i * y + j * x - i * j;
                    cost[k][i + j] = min(cost[k][i + j], cur);
                }
            }
        }
        for(auto k = 1; k <= n; k++){
            int x = a[k][0], y = a[k][1];
            for(int i = 0; i <= x + y; i++){
                //for(int j = 0; j <= y; j++){
                    //int cur = i * y + j * x - i * j;
                    //cout<<cost[k][i]<<" ";

            }
            //cout<<endl;
        }

       // int dp[n + 1][201];
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++){
            dp[i][0] = 0;
        }
        for(int i = 1; i <= n; i++){
            ///
        }

        for(int i = 1; i <= n; i++){
            //cout<<min(a[i][0] + a[i][1], kk)<<endl;
            for(int j = 0; j <= kk; j++){
                dp[i][j] = dp[i - 1][j];
                for(int k = 1; k <= j; k++){
                    int s = dp[i - 1][j - k] + cost[i][k];
                    dp[i][j] = min(dp[i][j], s);
                }
            }
        }
        if(dp[n][k] > 1e9)
            cout<<-1<<endl;
        else cout<<dp[n][k]<<endl;
    }
}

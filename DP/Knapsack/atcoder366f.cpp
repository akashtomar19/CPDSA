#include <bits/stdc++.h>
//int long long
#define int long long

using namespace std;

struct comp{
    bool operator()(auto& a, auto& b){
        return (a.first - 1) * b.second < (b.first - 1) * a.second;
    }
};

void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<pair<int, int>>a(n + 1);
    vector<int>b(n + 1);
    /// int gk = 0;
    for(int i = 1; i <= n; i++){
        int c, d;
        cin>>c>>d;
        a[i] = {c, d};
    }
    sort(a.begin() + 1, a.end(), comp());

    int pre = 1;
    vector<int>dp(k + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        vector<int>newdp(k + 1, 0);
        newdp[0] = 1;
        for(int j = 1; j <= k; j++){
            newdp[j] = max(dp[j], a[i].first * dp[j - 1] + a[i].second);
        }
        dp = newdp;
    }
    cout<<dp[k]<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
     //cin >> t;
    while(t--){
        solve();
    }
}

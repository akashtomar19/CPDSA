
#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>>dp;
int solve(vector<int>&a, int i, int totturnsbya){
    /// based on totturnsbya b can remove indexes
    if(i >= a.size()){
        return 0;
    }
    if(dp[i][totturnsbya] != -1)return dp[i][totturnsbya];
    int aa = 0, b =0;
    if(totturnsbya >= a[i]){ /// be can remove this if he has enough turns
        aa = solve(a, i + 1, totturnsbya - a[i]) + 1;
    }
    b = solve(a, i + 1, totturnsbya + 1); /// or else a will definitely pick up
    return dp[i][totturnsbya] = max(aa, b);
}
int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int>a;
        map<int, int>m;
        for(int i = 1; i <= n; i++){
            int x;
            cin>>x;
            m[x]++;
        }
        //memset(dp, -1, sizeof(dp));
        dp.resize(m.size() + 1, vector<int>(n + 1, -1));
        dp.assign(m.size() + 1, vector<int>(n + 1, -1));
        for(auto p: m){
            a.push_back(p.second);
        }
        cout<<a.size() - solve(a, 0, 0)<<endl;
    }
}


# include<bits/stdc++.h>
// # include<vector>
// #include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        vector<int>dp(n + 1, 0);
        int cnt = 0;
        int pre = -1;
        int res = 0;
        unordered_map<int, int>freq;
        unordered_map<int, unordered_map<int, int>>m;
        unordered_map<int, int>first;
        for(int i = 0; i < n; i++){
            freq[a[i]]++;
            m[a[i]][freq[a[i]]] = i;
            if(freq[a[i]] >= a[i]){
                int preind = m[a[i]][freq[a[i]] - a[i] + 1];
                dp[i + 1] = max(dp[i], dp[preind - 1 + 1] + a[i]);
            } else dp[i + 1] = dp[i];


            
            res = max(res, dp[i + 1]); 
            // if(i == 5){
            //     cout<<dp[i + 1]<<endl;
            // }
        }
        cout<<res<<endl;
    }
}


// 1 1 1 3 3 2 3

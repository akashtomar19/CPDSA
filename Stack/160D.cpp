//https://codeforces.com/contest/1913/problem/D
#include <bits/stdc++.h>
using namespace std;

int mod = 998244353;
int main() {
    int t;
    string s;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int a[n + 1];
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        stack<int>st;
        int left[n + 1];
        for(int i = 1; i <= n; i++){
            while(st.size() and a[st.top()] >= a[i]){
                st.pop();
            }
            left[i] = st.size() ? st.top() : 0;
            st.push(i);
        }
        int dppre[n + 1];
        dppre[0] = 0;
        int dp[n + 1];
        dppre[1] = 1;
        dp[0] = 1;
        dp[1] = 1;
        int res[n + 1];
        res[0] = 0;
        res[1] = 1;
        for(int i = 1; i <= n; i++){
            //cout<<left[i]<<endl;
        }
        for(int i = 2; i <= n; i++){
            int l = left[i];
            //int r = ;
            ///dp[i] = dp[left[i]];
            if(!left[i])dp[i] = 1;
            else dp[i] = 0;
            int ex = dppre[i - 1] - (left[i] ? dppre[left[i]] : 0);
            ex += mod;
            ex %= mod;
            dp[i] += ex + res[l];
            dp[i] %= mod;
            dppre[i] = dppre[i - 1] + dp[i];
            dppre[i] %= mod;
            res[i] = res[l] + dp[i];
            res[i] %= mod;
            //cout<<ex<<" "<<dp[i]<<endl;
        }
        cout<<res[n]<<endl;
    }
    return 0;
}

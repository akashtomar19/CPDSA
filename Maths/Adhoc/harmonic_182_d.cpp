#include<vector>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#define int long long
using namespace std;

int mod = 998244353;

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        int y;
        cin>>y;

        vector<int>a(n);
        int N = (4 * (1e5)) + 1;
        vector<int>freq(N + 1, 0);
        vector<int>pref(N + 1, 0);

        for(int i = 0; i < n; i++){
            cin>>a[i];
            freq[a[i]]++;
        }

        for(int i = 1; i <= N; i++){
            pref[i] += pref[i - 1] + freq[i];
        }

        

        int res = -10e14;

        for(int x = 2; x <= N/2; x++){ // if we are choosing x
            int curres = 0;
            for(int j = 1; j * x <= N; j++) {
                int cur = pref[j * x] - pref[(j - 1) * x];
                int avail = freq[j];
                int req = cur;
                curres += cur * j - max(req - avail, 1LL*0) * y;
            }
            // if(curres == 0)
            // cout<<x<<endl;
            res = max(res, curres);
        }
        cout<<res<<endl;        
    }
}


// 1
// 1 1000000000
// 200000
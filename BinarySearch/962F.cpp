
#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>>dp;
int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int>a, b;
        map<int, int>m;
        for(int i = 1; i <= n; i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        for(int i = 1; i <= n; i++){
            int x;
            cin>>x;
            b.push_back(x);
        }
        int l = 1;
        int r = 1e9;
        int res = 0;
        function<pair<int, int>(int)> check = [&](int x){
            int mx = x;
            int cnt = 0;
            int sum = 0;
            for(int i = 0; i < n; i++){
                if(a[i] < mx)continue;
                /// cnt
                int cur = (a[i] - mx)/b[i] + 1;
                cnt += cur;

                /// sum
                sum += (cur * a[i]) - ((cur - 1) * (cur) / 2 * b[i]);
            }
            return make_pair(sum, cnt);
        };
        int lmid = 1e9;
        while(l <= r){
            int mid = (l + r) / 2;
            int mx = mid;
            int cnt = 0;
            int sum = 0;
            auto tempCheck = check(mid);
            if(tempCheck.second <= k){
                res = tempCheck.first;
                lmid = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        int req = k - check(l).second;
        res += min(req, check(l - 1).second) * (l - 1);

        cout<<res<<endl;
    }
}

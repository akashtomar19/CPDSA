/**
 * https://codeforces.com/contest/1993/submission/279892840
 * https://codeforces.com/contest/1993/submission/274352424
 */
#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int x;
        vector<int>d(2 * k + 1, 0);
        int mx = 0;
        for(int i = 0; i < n; i++){
                cin>>x;
                mx = max(mx, x);
                x = x % (2 * k);
                if(x <= k){
                    d[x]++;
                    d[x + k]--;
                } else {
                    d[x]++;
                    d[2 * k]--;
                    d[0]++;
                    d[x - k]--;
                }
        }
        int res = 1e12;
        int K = k;
        for(int i = 0; i < 2 * k; i++){
            d[i] += (i ? d[i - 1] : 0);
            if(d[i] == n){
                //int64_t current = mx + (i + 2 * K - mx % (2 * K)) % (2 * K);
                res = min(res, mx + ((i - ((mx % (2 * k))) + 2*k) % (2*k)));
                //res = min(res, current);

            }
        }
        // cout<<res<<endl;

        if(res == 1e12){
            cout<<-1<<endl;
        } else cout<<res<<endl;

    }
}

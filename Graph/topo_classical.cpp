// https://codeforces.com/contest/1931/problem/F
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin>>n>>k;
        vector<unordered_set<int>>gp(n + 1);
       // cout<<n<<k<<endl;
        vector<int>indeg(n + 1, 0);
        for(int i = 0; i < k; i++){
            int pre = -1;
            for(int j = 0; j < n; j++){
                int x;
                cin>>x;
                //cout<<x<<endl;
                if(j > 1){
                    if(gp[pre].count(x) == 0){
                        indeg[x]++;
                        gp[pre].insert(x);
                    }
                    
                    
                    
                }
                pre = x;
            }
        }
        queue<int>q;

        for(int i = 1; i <= n; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
            //cout<<i<<" "<<indeg[i]<<endl;
        }
        while(q.size()){
            auto u = q.front();
            //cout<<u<<endl;
            q.pop();
            n--;
            for(auto v: gp[u]){
                if(--indeg[v] == 0){
                    q.push(v);
                }
            }
        }
        if(n == 0){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }

    }

    return 0;
}


#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int t0, t1, t2;
        cin>>t0>>t1>>t2;
        vector<vector<vector<int>>>gp(n + 1, vector<vector<int>>());
        auto inter = [&](int a, int b){
            if(b <= t1 || a >= t2)return false;
            return true;
        };
        for(int i = 0; i < m; i++){
            int u, v, li1, li2;
            cin>>u>>v>>li1>>li2;
            gp[u].push_back({v, li1, li2});
            gp[v].push_back({u, li1, li2});
        }
        set<pair<int, int>>st;
        vector<int>dist(n + 1, -1e9);
        dist[n] = t0;
        st.insert({t0, n});
        while(st.size()){
            auto node = st.rbegin()->second;
            auto time = st.rbegin()->first;
            st.erase(prev(st.end()));
            //cout<<node<<" "<<time<<endl;
            for(auto child: gp[node]){
                int v = child[0];
                int li1 = child[1];
                int li2 = child[2];
                int cur = time - li2;
                if(inter(time -li1, time)){
                    cur = max(cur, t1 - li1);
                } else cur = max(cur, time - li1);
                if(node == 5){
                    //cout<<v<<" # "<<cur<<endl;
                }
                if(dist[v] >= cur)continue;
                if(dist[v] != -1e9){
                    st.erase({dist[v], v});
                }

                dist[v] = cur;
                st.insert({cur, v});
            }
        }
        if(dist[1] < 0)cout<<-1<<endl;
        else cout<<dist[1]<<endl;
    }
}

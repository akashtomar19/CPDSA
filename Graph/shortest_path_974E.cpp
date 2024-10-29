#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, h;
        cin>>n>>m>>h;
        vector<vector<pair<int, int>>>gp(n + 1);
        vector<int>horse(n + 1, 1);
        for(int i = 1; i <= h; i++){
            int x;
            cin>>x;
            horse[x] = 0;
        }
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin>>u>>v>>w;
            gp[u].push_back({v, w});
            gp[v].push_back({u, w});
        }

        function<int(int, vector<vector<int>>&, int)> dijkstra = [&](int start, vector<vector<int>>&dist, int endv){
            set<pair<int, pair<int, int>>>pq;
            //vector<vector<bool>>vis(n + 1, vector<bool>(2, false));
            //vis[start][1] = true;
            pq.insert({0, {horse[start], start}});
            dist[start][horse[start]] = 0;

            while(pq.size()){
                auto cur = *pq.begin();
                pq.erase(cur);
                if(cur.second.second == endv)return -1;


                int u = cur.second.second, wu = cur.first, h = cur.second.first;
                //if(vis[u][h])continue;
                //cout<<u<<" # "<<wu<<" # "<<h<<endl;
                //vis[u][h] = true;
                for(auto& p: gp[u]){
                    int v = p.first;
                    int ww = p.second;
                    int curw = 0;
                    ///if(vis[v])continue;
                    if(u == 2){
                     //   cout<<v<<" "<<ww<<" "<<wu<<endl;
                    }
                    if(h == 0){
                        curw = ww/2 + wu;
                    } else curw =  ww + wu;
                    int curh = horse[v] == 0 || h == 0;
                    if(curw < dist[v][!curh]){

                        pq.erase({dist[v][!curh], {!curh, v}});
                        dist[v][!curh] = curw;

                        pq.insert({curw, {!curh , v}});
                    }
                }
            }
            return 0;
        };
        vector<vector<int>>dist1(n + 1, vector<int>(2, 1e16)), dist2(n + 1, vector<int>(2, 1e16));
        dijkstra(1, dist1, n);
        //cout<<endl;
        dijkstra(n, dist2, 1);
        int res = 1e16;
        for(int i = 1; i <= n; i++){
            //cout<<dist1[i][0]<<" "<<dist1[i][1]<<" ## "<<dist2[i][0]<<" "<<dist2[i][1]<<endl;
            int mn1 = min(dist1[i][0], dist1[i][1]);
            int mn2 = min(dist2[i][0], dist2[i][1]);
            int mx = max(mn1, mn2);
            res = min(mx, res);
        }
        if(res >= 1e16){
            cout<<-1<<endl;
        } else cout<<res<<endl;

    }
}

// https://codeforces.com/contest/1092/problem/E
#include <iostream>
#include <vector>
#include <string>
#include<set>
#include<bits/stdc++.h>
#define int long long
using namespace std;

using i64 = long long;
int n, k;
vector<vector<int>>gp;
vector<int>cur;
vector<int>used;
int ll = 0;
void dfs(int u){

    if(!used[u]){
        used[u] = true;
        cur.push_back(u);
        for(int v: gp[u]){
            dfs(v);
        }
    }
}
int bfs(int u, vector<int>& dist){
    queue<int>q;
    q.push(u);
    int level = 0;
    int r = u;
    dist[u] = 0;
    while(q.size()){
        int sz = q.size();
        level++;
        while(sz--){
            auto cr = q.front();
            q.pop();
            for(int v: gp[cr]){
                if(dist[v] == 1e9){
                    q.push(v);
                    dist[v] = level;
                    ll = level;
                    r = v;
                }
            }
        }
    }
    return r;
}
int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    gp.resize(n + 1);
    used.resize(n + 1, false);
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    vector<pair<int, int>>comp;
    vector<int>distx(n + 1, 1e9);
    vector<int>disty(n + 1, 1e9);
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            cur.clear();
            ll = 0;
            dfs(i);

            int x = bfs(i, distx);
            int y = bfs(x, disty);
            int center = -1;
            for(int i: cur){
                distx[i] = 1e9;
            }
            bfs(y, distx);
            int d = distx[x];
            for(int i: cur){
                if(distx[i] == d / 2 and disty[i] == (d - d / 2)){
                    center = i;
                    break;
                }
            }
            comp.push_back({d, center});
        }
    }
    sort(comp.begin(), comp.end());

    vector<vector<int>>ans;
    for(int i = 0; i < (int)comp.size() - 1; i++){
        int u = comp[i].second;
        int v = comp.back().second;
        gp[u].push_back(v);
        gp[v].push_back(u);
        ans.push_back({u, v});
    }
    vector<int>dist(n + 1, 1e9);
    int f = bfs(comp.back().second, dist);
    dist.assign(n + 1, 1e9);
    int s = bfs(f, dist);
    cout<<dist[s]<<endl;
    for(auto v: ans){
        cout<<v[0]<<" "<<v[1]<<endl;
    }


    return 0;
}

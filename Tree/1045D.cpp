
// #include<vector>
// #include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>gp;
        gp.resize(n);

        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin>>u>>v;
            u--;
            v--;
            gp[u].push_back(v);
            gp[v].push_back(u);
        }
        vector<int>dist(n, 0);
        vector<int>pars(n, -1);

        function<void(int, int, int)>dfs = [&](int u, int h, int par){
            dist[u] = h;
            pars[u] = par;
            for(int v: gp[u]) {
                if(v == par)continue;
                dfs(v, h + 1, u);
            }
        };

        dfs(0, 0, -1);
        
        int mx = *max_element(dist.begin(), dist.end());
        int x = -1;
        int y = -1;

        for(int i = 0; i < n; i++){
            if(mx == dist[i]){
                x = i;
                break;
            }
        }

        dfs(x, 0, -1);

        mx = *max_element(dist.begin(), dist.end());

        if(mx == n - 1){
            cout<<-1<<endl;
        } else {

            for(int i = 0; i < n; i++){
                if(dist[i] == mx){
                    y = i;
                    break;
                }
            }

            // cout<<x + 1<<" # "<<y + 1<<endl;

            vector<bool>onDiameter(n, false);

            while(y != -1){
                onDiameter[y] = true;
                y = pars[y];
            }

            for(int i = 0; i < n; i++){
                auto done = false;
                for(int v: gp[i]){
                    if(onDiameter[i] and !onDiameter[v]){
                        /// i, v, par[i]
                        int a = pars[i];
                        int b = i;
                        int c = v;

                        done = true;

                        cout<<a + 1<<" "<<b + 1<<" "<<c + 1<<endl;

                        break;

                    }
                }
                if(done){
                    break;
                }
            }
        }

    }
}
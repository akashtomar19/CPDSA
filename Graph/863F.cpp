#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include<bits/stdc++.h>

#define int long long
using namespace std;

const int mod = 1e9 + 7;


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<int>gp[n + 1];
        vector<int>deg(n + 1, 0);
        for(int i = 1; i <= m; i++){
            int u, v;
            cin>>u>>v;
            gp[u].push_back(v);
            gp[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        set<int>st;
        int two = 0, other = 0;
        for(int i = 1; i <= n; i++){
            if(deg[i]){
                st.insert(deg[i]);
            }
            if(deg[i] == 2)two++;
            else if(deg[i])other++;
        }
        if(two + other != n){
            cout<<"NO"<<endl;
            continue;
        }
        if(st.size() > 2 || *st.begin() != 2 || st.size() < 2){
            cout<<"NO"<<endl;
            continue;
        }
        if(two % other){
            cout<<"NO"<<endl;
            continue;
        }
        //cout<<111111<<endl;
        //vector<int>dist(n + 1, 0);
        function<bool(int, int, int, int)> dfs = [&](int u, int par, int root, int d){
            //cout<<u<<" "<<d<<endl;
            if(u == root and d){
                if((d) % other)return false;
                return true;
            }

            for(int v: gp[u]){
                if(v != root and deg[v] != 2)continue;
                if(v == par)continue;
                if(dfs(v, u, root, d + 1))return true;
                //else return false;
            }
            return false;
        };
        //cout<<*st.rbegin()<<endl;

        function<bool(int, int, int, int)> dfs2 = [&](int u, int par, int root, int d){
           // cout<<u<<" "<<d<<endl;
            if(u == root and d){
                if((d) % other)return false;

                return true;
            }

            for(int v: gp[u]){
                //cout<<v<<" "<<deg[v]<<endl;
                if(deg[v] != *st.rbegin())continue;
                if(v == par)continue;
                if(dfs2(v, u, root, d + 1))return true;
                //else return false;
            }
            return false;
        };
        bool bad = false;

        for(int i = 1; i <= n; i++){
            if(deg[i] == *st.rbegin()){
                if(!dfs(i, -1, i, 0)){
                    bad = true;
                    break;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(deg[i] == *st.rbegin()){
                if(!dfs2(i, -1, i, 0)){
                    bad = true;
                }
                break;
            }
        }

        if(!bad){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }

    }
}



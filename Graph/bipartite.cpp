

#include<bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>>m;
vector<int>color;
vector<vector<int>>gp;
int dfs(int u, int col){
    //cout<<u<<" "<<color[u]<<endl;
    if(color[u] == (col^1))return false;

    if(color[u] == col)return true;
    //cout<<u<<" "<<col<<endl;
    color[u] = col;
    m[col].push_back(u);
    for(int v: gp[u]){
        if(!dfs(v, col ^ 1)){
            return false;
        }
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        m.clear();
        color.clear();
        gp.clear();
        int n, mm;
        cin>>n>>mm;

        gp.resize(n + 1);

        color.resize(n + 1, -1);

        for(int i = 1; i <= mm; i++){
            int u, v;
            cin>>u>>v;
            gp[u].push_back(v);
            gp[v].push_back(u);
        }
        auto d = dfs(1, 1);
        for(auto mmm: m){
            for(auto p: mmm.second){
               // cout<<p<<" ";
            }
            //cout<<endl;
        }
        if(!d){ /// alice 1 2
            cout<<"Alice"<<endl;
            for(int i = 0; i < n; i++){
                cout<<1<<" "<<2<<endl;
                int x;
                cin>>x>>x;
            }
        } else {
            cout<<"Bob"<<endl;
            for(int i = 0; i < n; i++){
                int col1, col2;

                cin>>col1>>col2;
                if(!m[0].size()){
                    int rr =  3;
                    if(col1 == 2 or col2 == 2){
                        rr = 2;
                    }
                    cout<<m[1].back()<<" "<<rr<<endl;
                    m[1].pop_back();
                } else if(!m[1].size()){
                    int rr =  3;
                    if(col1 == 1 or col2 == 1){
                        rr = 1;
                    }
                    cout<<m[0].back()<<" "<<rr<<endl;
                    m[0].pop_back();
                } else {
                    if(col1 != 3){
                        cout<<m[col1 - 1].back()<<" "<<col1<<endl;
                        m[col1 - 1].pop_back();
                    } else {
                        cout<<m[col2 - 1].back()<<" "<<col2<<endl;
                        m[col2 - 1].pop_back();
                    }
                }
            }
        }
    }
}

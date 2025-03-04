#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>gp;
vector<int>f;
int res = -1;
void dfs(int u, int par){
    f[u] = 1;
    vector<int>seq;
    for(int v: gp[u]){
        if(v == par)continue;
        dfs(v, u);
        seq.push_back(f[v]);
    }
    sort(seq.begin(), seq.end());
    reverse(seq.begin(), seq.end());

    if(seq.size() >= 3){
        f[u] = seq[0] + seq[1] + seq[2] + 1;
    }
    if(seq.size() >= 4){
        res = max(res, seq[0] + seq[1] + seq[2] + seq[3] + 1);
    }
    if(seq.size()){
        res = max(res, seq[0] + 1);
    }
}
int main(){
    int n;
    cin>>n;
    gp.resize(n);
    f.resize(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    dfs(0, -1);
    if(res <= 4)
        cout<<-1<<endl;
    else
        cout<<res<<endl;

}

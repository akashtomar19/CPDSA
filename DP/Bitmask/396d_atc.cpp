#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
  int n, m;
  cin>>n>>m;
  vector<vector<pair<int, int>>>gp(n);

  for(int i = 0; i < m; i++){
    int u, v;
    cin>>u>>v;
    u--;
    v--;
    int w;
    cin>>w;
    gp[u].push_back({v, w});
    gp[v].push_back({u, w});
  }
  int res = 2*1e18;

  function<void(int, int, int)> dfs = [&](int u, int mask, int xr){
    if(u == n - 1){
      res = min(res, xr);
    }

    for(auto vv: gp[u]){
      int v = vv.first;
      int w = vv.second;
      if((mask & (1 << v)) == 0){
        dfs(v, mask | (1 << v), xr ^ w);
      }
    }
  };
  dfs(0, 1, 0);
  cout<<res<<endl;
}
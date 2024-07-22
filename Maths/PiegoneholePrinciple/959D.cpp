
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n + 1);
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        vector<pair<int, int>>res;
        vector<int>vis(n + 1, false);
        for(int i = n - 1; i >= 1; i--){
            map<int, int>mods;
            for(int j = 1; j <= n; j++){
                int cur = a[j] % i;
                if(vis[j])continue;
                if(mods.count(cur)){
                    vis[j] = true;
                    res.push_back({j, mods[cur]});
                    break;
                }
                mods[cur] = j;
            }
        }
        cout<<"YES"<<endl;
        reverse(res.begin(), res.end());
        for(auto p: res){
            cout<<p.first<<" "<<p.second<<endl;
        }
    }
}

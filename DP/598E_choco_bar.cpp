#include<bits/stdc++.h>
using namespace std;
int cache[31][31][51];
int solve(int x, int y, int k){
    if(k < 0)return 1e9;
    if(k == 0)return 0;
    if(x * y < k)return 1e9;
    if(x * y == k)return 0;
    int res = 1e9;
    int &ans = cache[x][y][k];
    if(ans != -1)return ans;
    for(int i = 1; i <= x - 1; i++){
        for(int j = 0; j <= k; j++){
            int left = solve(i, y, j);
            int right = solve(x - i, y, k - j);
            int cost = y * y;
            int curcost = left + right + cost;
            res = min(res, curcost);
        }
    }

    for(int i = 1; i <= y - 1; i++){
        for(int j = 0; j <= k; j++){
            int up = solve(x, i, j);
            int down = solve(x, y - i, k - j);
            int cost = x * x;
            int curcost = up + down + cost;
            res = min(res, curcost);
        }
    }
    return ans = res;
}
int main(){
    int t;
    cin>>t;
    memset(cache, -1, sizeof(cache));
    while(t--){
        int n, m, k;
        cin>>n>>m>>k;
        int res = solve(n, m, k);
        cout<<res<<endl;
    }
}

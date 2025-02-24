#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);


    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>a;
    vector<int>acnt(1e6 + 1, 0);
    int m = 1e6;
    //cout<<1<<endl;
    int mx = 1;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        a.push_back(x);
        mx = max(mx, x);
        acnt[x]++;
    }
    //cout<<2<<endl;

    unordered_map<int, int>res, ans;
    for(int d = 1; d <= mx; d++){
        for(int j = d; j <= mx; j+=d){
            res[d] += acnt[j];
        }
    }
    //cout<<1<<endl;


    for(int d = 1; d <= mx; d++){
        for(int j = d; j <= mx; j+=d){
            if(res[d] >= k){
                if(acnt[(j)]){
                    ans[j] = d;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout<<ans[a[i]]<<endl;
    }
}

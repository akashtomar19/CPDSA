// https://codeforces.com/contest/1991/problem/D

#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>>dp;
constexpr int ans[][5] = {
{},
{1},
{1, 2},
{1, 2, 2},
{1, 2, 2, 3},
{1, 2, 2, 3, 3}
};

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        if(n <= 5){
            int mx = *max_element(ans[n], ans[n] + n);
            cout<<mx<<endl;
            for(int j = 1; j <= n; j++){
                cout<<ans[n][j - 1]<<" ";
            }
            cout<<endl;
        } else {
            cout<<4<<endl;
            for(int j = 1; j <= n; j++){
                cout<<(j % 4) + (j % 4 == 0 ? 4 : 0)<<endl;
            }
        }
    }
}

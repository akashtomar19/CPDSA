
#include<vector>
#include<iostream>
#define int long long

// #include<bits/stdc++.h>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n + 1);

        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }

        int res = 0;

        for(int i = 2; i <= n; i += 2){
            int cur = max((a[i - 1] + (i + 1 <= n ? a[i + 1] : 0)) - a[i], 1LL*0);
            res += cur;
            if(i + 1 <= n)a[i + 1] -= cur;
            a[i + 1] = max(a[i + 1], 1LL*0);
        }

        cout<<res<<endl;
    }
}
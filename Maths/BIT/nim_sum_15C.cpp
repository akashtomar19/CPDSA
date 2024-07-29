#include <bits/stdc++.h>
using namespace std;

#define int long long

int getXor(int x){
    if(x % 4 == 0){
        return x;
    }
    if(x % 4 == 1){
        return 1;
    }
    if(x % 4 == 2){
        return x + 1;
    }
    return 0;
}
/**
xi xi + 1 xi + 2 .. xi + m - 1
**/
void solve() {
    int x, m;
    int n;
    cin>>n;
    int res = 0;
    while(n--){
        cin>>x>>m;
        int p = getXor(x - 1) ^ getXor(x + m - 1);
        res = res ^ p;
    }
    if(res){
        cout<<"tolik"<<endl;
    } else {
        cout<<"bolik"<<endl;
    }
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    t = 1;
    while (t--) {
        solve();
    }

    return 0;
}

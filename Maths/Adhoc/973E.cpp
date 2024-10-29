#include <bits/stdc++.h>
#define int long long

using namespace std;

int a[200200];
int n;
void dbg(stack<pair<int, int>>st){
    while(st.size()){
        auto cur = st.top();
        cout<<cur.first<<" "<<cur.second<<endl;
        st.pop();
    }
}
int gcd(int a, int b){
    if(a == 0)return b;
    return gcd(b%a, a);
}

void solve(){
    int n;
    cin>>n;
    vector<int>a(n + 1);
    int gk = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        a[i] = x;
        gk = gcd(gk, x);
    }
    for(int i = 1; i <= n; i++){
        a[i] /= gk;
    }
    /**
      7 * 3 * 5, 7 * 3, 7
    **/
    int ans = 0;
    int curmin = 0;
    int g = 0;
//    int ans = 0;
    for(int t = 1; t <= 10; t++){
        int curmin = 1e9;
        for(int i = 1; i <= n; i++){
            int cur = gcd(g, a[i]);
            curmin = min(curmin, cur);
        }
        //cout<<"# "<<curmin<<endl;
        g = curmin;
        ans += curmin;
        if(curmin == 1){
            ans += n - t;
            break;
        }

    }
    cout<<ans * gk<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
     cin >> t;
    while(t--){
        solve();
    }
}

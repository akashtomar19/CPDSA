#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, a, b;
        cin>>n>>a>>b;
        int g = __gcd(a, b);
        set<int>st;
        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            st.insert(x % g);
        }
        int j = 0, res = 1e9;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            res = min(res, *st.rbegin() - *st.begin());
            auto it = *st.begin();
            st.erase(st.begin());
            it+=g;
            st.insert(it);
        }
        cout<<res<<endl;
    }
}

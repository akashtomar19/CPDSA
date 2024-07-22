
//https://codeforces.com/contest/1976/problem/D
#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        //cin>>n;
        string s;
        cin>>s;
        map<int, int>st;
        int bal = 0;
        int res = 0;
        for(auto c: s){
            bal += (c == '(' ? 1: -1);
            res += st[bal];
            st[bal]++;
            while(st.size() and 2 * st.begin()->first < bal){
                st.erase(st.begin());
            }
        }
        cout<<res<<endl;
    }
}

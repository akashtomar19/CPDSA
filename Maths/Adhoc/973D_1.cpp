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

void solve(){
    int n;
    cin>>n;
    vector<int>a(n + 1);
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        a[i] = x;
    }
    /**
    4 3
    4 5 1
    4 5 2
    3 4 3
    3 4 2
    3 3 3
    4 3 2
    **/

    stack<pair<int, int>>st;
    for(int i = 1; i <= n; i++){
        int cur = a[i];
        int cnt = 1;
        while(st.size() and st.top().first >= cur / cnt){
            cur += st.top().first * st.top().second;
            cnt += st.top().second;
            st.pop();
        }
        st.push({cur / cnt, cnt});
        // cout<<cur<<" "<<cnt<<endl;
        //dbg(st);

        if(cur % cnt){
            st.top().second -= cur%cnt;
            st.push(st.top());
            st.top().second = cur%cnt;
            st.top().first += 1;
        }

    }
    int mn = 1e16, mx = 0;
    //dbg(st);
    while(st.size()){
        mx = max(st.top().first, mx);
        mn = min(st.top().first, mn);
        st.pop();
    }
    cout<<""<<mx-mn<<endl;
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

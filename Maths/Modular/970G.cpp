#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        //int n, a, b;
        int n, k;
        cin>>n>>k;
        vector<int>a(n + 1);
        for(int i = 1; i <= n; i++){
            int x;
            cin>>x;
            a[i] = x;
        }
        int g = a[1];
        for(int i = 2; i <= n; i++){
            g = __gcd(a[i], g);
        }
        vector<int>st;
        for(int i = 1; i <= n; i++){
            st.push_back((i - 1) * g);
            //cout<<st.back()<<" ";
        }
        //cout<<endl;
        if(n == 1)st[0] = a[1];
        if(st[0] >= k){
            cout<<k - 1<<endl;
            continue;
        }
        int pre = st[0];
        k -= st[0];
        for(int i = 2; i <= n; i++){
            int cur = st[i - 1];
            if(cur - pre - 1 >= k){
                break;
            }
            k -= (cur - pre - 1);
            pre = cur;
        }
        cout<<pre + k<<endl;
    }
}

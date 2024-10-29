#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, k;
        cin>>n>>m>>k;

        vector<pair<int, int>>a;
        for(int i = 0; i < n; i++){
            int di, ai;
            cin>>di>>ai;
            a.push_back({di, ai});
        }
        a.push_back({1e9, 0});
        list<pair<int, int>>pq;
        int curd = 0;
        int res = 0;
        for(int i = 0; i <= n; i++){
            int rem = 0;
            //cout<<" # i # "<<i<<endl;
            while(pq.size()){
                auto cur = pq.back();
                pq.pop_back();
                int nxt = a[i].first - curd;
                if(i == 2){
                    //cout<<cur.first<<" "<<cur.second<<" "<<k<<" "<<curd<<endl;
                }
                int kval = cur.first + k - curd;
                int can = (cur.second + rem) / m;

                int take = max(0LL, min({nxt, kval, can}));
                int rem1 = cur.second + rem - m * take;

                res += take;
                curd += take;
                //cout<<" nxt "<<nxt<<" kval "<<kval<<" can "<<can<<" take "<<take<<" curd "<<curd<<endl;
                rem = rem1;
                if(curd == a[i].first){
                    pq.push_back({cur.first, rem1});
                    break;
                }
            }
            curd = a[i].first;
            pq.push_back(a[i]);
        }
        cout<<""<<res<<endl;
    }
}

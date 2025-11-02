


// #include<vector>
// #include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, q;
        cin>>n>>m>>q;

        vector<int>a;

        vector<int>b;

        vector<int>prefx(1, 0);

        vector<int>prefy(1, 0);

        for(int i = 0; i < n; i++) {
            int x;
            cin>>x;
            a.push_back(x);
            // prefx.push_back(prefx.back() + x);
        }

        for(int i = 0; i < m; i++) {
            int x;
            cin>>x;
            b.push_back(x);
            // prefy.push_back(prefy.back() + x);
        }

        sort(a.rbegin(), a.rend());

        sort(b.rbegin(), b.rend());

        // for(int i = 0; i < n; i++){
        //     cout<<b[i]<<" hey ";
        // }
        // cout<<endl;

        for(int i = 0; i < n; i++) {
            
            prefx.push_back(prefx.back() + a[i]);
        }

        for(int i = 0; i < m; i++) {
            
            prefy.push_back(prefy.back() + b[i]);
        }

        // cout<<-1<<endl;
        int tempq =q;

        
        
        int ind = 0;
        vector<vector<int>>queries;
        while(q--){
            int x, y, z;
            cin>>x>>y>>z;
            queries.push_back({x, y, z});
            // m[z].push_back({ind, x, y});
            // ind++;
        }
        int l = 0; 
        int r = 0;
        vector<vector<int>>zvals(n + m + 10);
        zvals[0] = {0, 0};

        while(l < n and r < m){
            if(a[l] >= b[r]){
                l++;
            } else r++;
            zvals[l + r] = {l, r};
        }

        while(l < n){
            l++;
            zvals[l + r] = {l, r};
        }

        while(r < m){
            r++;
            zvals[l + r] = {l, r};
        }

        // cout<<-2<<endl;
        // cout<<-8<<endl;

        
        // cout<<-3<<endl;
        // cout<<zvals[4][0]<<" "<<zvals[4][1]<<" "<<prefx[3]<<" "<<prefy[1]<<endl;
        // for(int i = 0; i <= m; i++){
        //     cout<<prefy[i]<<" ";
        // }
        // cout<<endl;
        q = tempq;
        vector<int>res(q);

        function<int(int, int)>check = [&](int mid, int z){
            return prefx[mid] + prefy[z - mid];
        };

        for(int i = 0; i < q; i++){
            
            int x, y, z;
            // cout<<-5<<endl;
            x = queries[i][0];
            y = queries[i][1];
            z = queries[i][2];
            
            int l = max(1LL*0, z - y);
            int r = min(z, x);

            int ress = 0;

            while(r - l > 2){
                
                int mid1 = (2*l + r) / 3;
                int mid2 = (2*r + l) / 3;

                int val1 = check(mid1, z);
                int val2 = check(mid2, z);

                if(val1 < val2){
                    // ress = mid2;
                    l = mid1 + 1;
                } else if(val1 > val2) {
                    // ress = mid1;
                    // r = mid2;
                    r = mid2 - 1;
                } else {
                    r = mid2 - 1;
                }

            }

            for(int k = l; k <= r; k++){
                ress = max(ress, prefx[k] + prefy[z - k]);
            }
            res[i] = ress;
        }

        for(int i = 0; i < q; i++){
            cout<<res[i]<<endl;
        }
        
    }
}

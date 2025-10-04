
#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int q;
        cin>>q;
        vector<int>a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        vector<int>st;
        vector<int>mxl(n), mnl(n);

        for(int i = 0; i < n; i++){
            while(st.size() and a[st.back()] < a[i]){
                st.pop_back();
            }
            mxl[i] = st.size() ? st.back() : -1;
            st.push_back(i);
        }
        st.clear();

        for(int i = n - 1; i >= 0; i--){
            while(st.size() and a[st.back()] > a[i]){
                st.pop_back();
            }
            mnl[i] = st.size() ? st.back() : -1;
            st.push_back(i);
        }

        vector<vector<int>>s;

        for(int i = 0; i < n; i++){
            if(mxl[i] != -1 and mnl[i] != -1){
                s.push_back({mxl[i], mnl[i]});
                // cout<<mxl[i]<<" "<<mnl[i]<<endl;

            }
        }

        
        vector<vector<int>>p;
        int i = 0;
        int qq = q;
        while(q--){
            int u, v;
            cin>>u>>v;
            p.push_back({u, v, i++});
        }
        // cout<<-2<<endl;

        sort(s.begin(), s.end(), [&](vector<int>& x, vector<int>& y){return x[1] < y[1];});
        sort(p.begin(), p.end(), [&](vector<int>& x, vector<int>& y){return x[1] < y[1];});

        int mx = -1;
        int ind = 0;

        vector<int>res(qq);
        // cout<<-1<<endl;

        for(auto& q: p){
            int l = q[0] - 1;
            int r = q[1] - 1;
            int resind = q[2];

            while(ind < s.size() and s[ind][1] <= r){
                mx = max(mx, s[ind][0]);
                ind++;
            }
            // cout<<l<<" "<<r<<" "<<mx<<endl;
            if(l <= mx){
                res[resind] = 0;
            } else {
                res[resind] = 1;
            }
        }
        for(int i = 0; i < qq; i++){
            if(res[i])
            cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        
    }
}


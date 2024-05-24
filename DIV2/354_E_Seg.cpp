#include<bits/stdc++.h>
using namespace std;
class seg{
public:

    vector<int>tree;
    seg(int n){
        tree.resize(4 * n + 12, 0);
    }
    int query(int ind, int l, int r, int start, int end){

        if(r < start || l > end)return INT_MIN;

        if(l <= start && end <= r)return tree[ind];

        if(start == end){
            return tree[ind];
        }

        int mid = (start + end) / 2;

        auto ll = query(2 * ind + 1, l, r, start, mid);
        auto rr = query(2 * ind + 2, l, r, mid + 1, end);

        return max({ll, rr});
    }
    int update(int ind, int l, int r, int start, int end, int val){

        if(r < start || l > end)return tree[ind];
        if(start == end){
            tree[ind] = val;
            return val;
        }
        long long int mid = start + (end - start) / 2;
        //int ll = 0, rr = 0;

        auto ll = update(2 * ind + 1, l, r, start, mid, val);
        //else
        auto rr = update(2 * ind + 2, l, r, mid + 1, end, val);

        tree[ind] = max(ll, rr);
        return tree[ind];
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        set<int>st;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            st.insert(a[i]);
        }
        int ind = 0;
        unordered_map<int, int>m;
        for(int i: st){
            if(m.count(i) == 0){
                m[i] = ind++;
            }
        }

        for(int i = 0; i < n; i++){
            a[i] = m[a[i]];
        }

        int left[n], right[n];
        auto l = seg(n);
        auto r = seg(n);

        int mx = 1;
        for(int i = 0; i < n; i++){
            int r = a[i] - 1;
            //left[i] = 1;
           // cout<<"print r "<<r<<endl;
            int cur = r < 0 ? 0: l.query(0, 0, r, 0, n);
            cur++;
            l.update(0, r + 1, r + 1, 0, n, cur);
            left[i] = cur;
            //cout<<cur<<" ";
            mx = max(mx, left[i]);
        }
        //cout<<"Hey "<<mx<<" ";
        //cout<<endl;
        for(int i = n - 1; i >= 0; i--){
            int rr = a[i] + 1;
            //right[i] = 1;
            int cur = r.query(0, rr, n, 0, n) + 1;
            //cout<<cur<<" ";
            r.update(0, rr - 1, rr - 1, 0, n, cur);
            right[i] = cur;

        }
        //cout<<endl;
        vector<int>res;
        for(int i = 0; i < n; i++){
            if(left[i] + right[i] - 1 == mx){
                res.push_back(i + 1);
            }
        }
        cout<<res.size()<<endl;
        for(auto r: res){
            cout<<r<<" ";
        }
        cout<<endl;
    }
}

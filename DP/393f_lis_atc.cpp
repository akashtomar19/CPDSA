
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, q;
    cin>>n>>q;
    vector<int>a;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    unordered_map<int, vector<vector<int>>>queries;
    for(int i = 0; i < q; i++){
        int r, x;
        cin>>r>>x;
        queries[r - 1].push_back({x, i});
    }
    vector<int>temp;
    vector<int>res(q);
    for(int i = 0; i < n; i++){
        int val = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
        if(val == temp.size()){
            temp.push_back(a[i]);
        } else {
            temp[val] = a[i];
        }
        for(auto t: temp){
            //cout<<t<<" ";
        }
        //cout<<endl;



        for(auto v: queries[i]){
            int val = upper_bound(temp.begin(), temp.end(), v[0]) - temp.begin();
            val -= 1;
            if(val < 0){
                res[v[1]] = 0;
            } else {
                res[v[1]] = val + 1;
            }
        }


    }
    for(int i = 0; i < q; i++){
        cout<<res[i]<<endl;
    }
}

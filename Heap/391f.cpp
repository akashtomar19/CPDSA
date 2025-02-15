#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin>>n;
    int kk;
    cin>>kk;
    vector<int>a, b, c;

    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        b.push_back(x);
    }
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        c.push_back(x);
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());

    auto f = [&](int i, int j, int k) {
    return a[i] * b[j] + b[j] * c[k] + c[k] * a[i];
};



    int l = 3;
    int r = 3 * 1e18;

    function<int(int)>check = [&](int x){
        int cnt = 0;
        //cout<<-1<<endl;
        for(int i = 0; i < n; i++){
            //if(a[i] > x)break;
            if(a[i] * b[0] + b[0] * c[0] + c[0] * a[i] < x)break;
            if(f(i, 0, 0) < x)break;
            for(int j = 0; j < n; j++){
                    //cout<<-2<<endl;
                //if(a[i] * b[j] <= x)break;
                if(a[i] * b[j] + b[j] * c[0] + c[0] * a[i] < x)break;
                if(f(i, j, 0) < x)break;
                for(int k = 0; k < n; k++){
                    //cout<<-3<<endl;
                    if(a[i] * b[j] + b[j] * c[k] + c[k] * a[i] < x)break;
                    if(f(i, j, k) < x)break;

                    cnt += 1;
                    //cout<<" # "<<x<<" "<<cnt<<endl;
                    //cout<<" what is the k "<<k<<endl;
                    //cout<<" what is the cnt "<<cnt<<endl;
                    if(cnt == kk){
                        //cout<<"cnt = k"<<endl;
                        return true;
                    }
                }
            }
        }
        return false;
    };

    int res = -1;

    while(l <= r){
        int mid = (l + r) / 2;
        // cout<<mid<<endl;

        auto st = check(mid);
        //cout<<" mid "<<mid<<" "<<st<<endl;

        if(st){
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if(res < 3)cout<<-1<<endl;
    cout<<res<<endl;
}
 
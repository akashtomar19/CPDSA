#include<bits/stdc++.h>
#define int long long
using namespace std;
int re, v;

int32_t main(){
    int n, k;
    cin>>n>>k;
    int p[n + 1];
    p[0] = 0;
    int a[n + 1];
    auto check = [&](int m){
        for(int i = m - 1; i < n; i++){
            int s = p[i + 1] - p[i + 1 - m];
            if(m * a[i] - s <= k){
                v = m;
                re = a[i];
                return true;
            }
        }
        return false;
    };
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        //p[i + 1] = p[i] + a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        //cin>>a[i];
        p[i + 1] = p[i] + a[i];
    }

    //cout<<1<<endl;
    int l = 1;
    int r = n;
    check(5);
    while(l <= r){
            //break;
        int mid = (l + r) / 2;
        if(check(mid)){
            l = mid + 1;
        } else r = mid - 1;
    }
    cout<<v<<" "<<re<<endl;
}

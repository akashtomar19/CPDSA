

#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t;
    t = 1;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);

        for(int &i : a){
            cin>>i;
        }

        sort(a.begin(), a.end());

        int l = 0;
        int m = n / 2;
        if(n & 1)m++;
        int res = 0;
        for(int i = 0; i < n / 2 and m < n; i++){
            while(m < n and a[m] < 2 * a[i])m++;
            if(m < n)
            res++;
            m++;
        }
        cout<<res<<endl;
    }
}

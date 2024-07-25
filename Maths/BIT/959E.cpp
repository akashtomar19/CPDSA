#include<bits/stdc++.h>

using namespace std;

void solve() {
    int k;
    cin >> k;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        for (int j = 0; j < a[i] - 1; ++j) {
            int trash;
            cin >> trash;
        }
    }
    sort(a.rbegin(), a.rend());
    int res = 0;
    for(int i = 0; i < k; i++){
        int j = a[i];
        int hs = -1;
        for(int s = 30; s >= 0; s--){
            if(j & (1 << s)){
                if((res & (1 << s)) == 0){
                    res = res | (1 << s);
                } else {
                    if(s >= 1)res |= ((1 << s) - 1);
                    break;
                }
            }
        }
    }
    cout<<res<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
int n, q, a[MAX_N], p[MAX_N];
bool canFormTwoTriangles(int l, int r) {
    int t = 0;
    for(int i = l; i <= r; i++){
        p[t++] = a[i];
    }
    sort(p, p + t);
    for(int i = 0; i < t - 5; i++){
        for(int j = i + 1; j < i + 6; j++){
            for(int k = j + 1; k < i + 6; k++){
                int q[3], s = 0;
                for(int l = i + 1; l < i + 6; l++){
                    if(l != j and l != k){
                        q[s++] = p[l];
                    }
                }
                if(q[0] + q[1] > q[2] and p[i] + p[j] > p[k]){
                    return true;
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < t - 2; i++){
        if(p[i] + p[i + 1] > p[i + 2]){
            cnt++;
            i+=2;
        }
    }
    return cnt > 1;
}
int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (r - l + 1 >= 48 || canFormTwoTriangles(l, r))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}

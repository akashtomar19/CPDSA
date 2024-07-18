#include <bits/stdc++.h>
#define int long long
using namespace std;
using i64 = long long;

std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }

        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

void solve() {
    int n;
    cin>>n;

    int m = 1;
    while(n - 1 > ((m % 2) ? (m * (m - 1) / 2 + m) : (m * (m - 1) / 2 + m - m/2 + 1))){
        m++;
    }
    //cout<<m<<endl;
    vector<vector<int>>a(m + 1, vector<int>(m + 1, 1));
    if(m % 2 == 0){
        for(int i = 1; i < m - 1; i+=2){
            a[i][i + 1] = a[i + 1][i] = 0;
        }
    }
    vector<int>res;

    function<void(int)> dfs = [&](int x){
        //cout<<x<<endl;
        for(int i = 0; i < m; i++){
            if(a[x][i]){
                a[x][i] = a[i][x] = 0;
                dfs(i);
            }
        }
        res.push_back(primes[x]);
    };
    dfs(0);

    for(int i = 0; i < n; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}


int32_t main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    sieve(3 * 1e5);

    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}

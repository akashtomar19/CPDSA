#include <bits/stdc++.h>
#define int long long
using namespace std;
using i64 = long long;
struct DSU {
    std::vector<int> f, siz;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};
void solve() {
    int n;
    cin>>n;
    vector<array<int, 3>>seg;
    int aa[n + 1];
    for(int i = 0; i < n; i++){
        int a,b,val;
        cin>>a>>b>>val;
        seg.push_back({a, 0, i});
        seg.push_back({b, 1, i});
        aa[i] = val;
    }
    sort(seg.begin(), seg.end());
    set<pair<int, int>>s;
    vector<array<int, 3>>edges;
    for(auto &p: seg){
        int t = p[1];
        int i = p[2];
        if(t == 0){
            auto it = s.emplace(aa[i], i).first;
            if(it != prev(s.end())){
                auto l = next(it);
                edges.push_back({l->first - it->first, l->second, it->second});
            }
            if(it != s.begin()){
                auto l = prev(it);
                edges.push_back({it->first - l->first, l->second, it->second});
            }
        } else {
            s.erase({aa[i], i});
        }
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    auto d = DSU(n + 1);
    for(auto &e: edges){
        if(d.merge(e[1], e[2])){
            ans += e[0];
        }
    }
    if(d.size(n - 1) != n){
        cout<<-1<<"\n";
    } else {
        cout<<ans<<"\n";
    }
}


int32_t main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;

    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}

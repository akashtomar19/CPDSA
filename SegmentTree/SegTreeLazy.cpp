// https://codeforces.com/contest/1976/problem/D
#include <bits/stdc++.h>

#define endl '\n'
#define ll long long int
#define let(x, a) __typeof(a) x(a)
#define all(a) (a).begin(), (a).end()
#define present(c, x) ((c).find(x) != (c).end())
#define tr(v, it) for (let(it, v.begin()); it != v.end(); it++)
#define rtr(v, it) for (let(it, v.rbegin()); it != v.rend(); it++)

using namespace std;

#ifdef DEBUG
#define trace1(x)                   cerr << #x << ": " << x << endl;
#define trace2(x, y)                cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)             cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)          cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif

// Segment Tree

template<typename T>
class SegmentTree {
private:
    int n;
    vector<T> tree;
    vector<T> lazy;

    int left(int pos) {
        return (pos << 1) + 1;
    }

    int right(int pos) {
        return (pos << 1) + 2;
    }

    int mid(int l, int r) {
        return ((l + r) >> 1);
    }

    T identity() {
        return 0;
    }

    T combine(T left, T right) {
        return max(left, right);
    }

    void lazyUpdate(int pos, int l, int r) {
        tree[pos] = max(tree[pos],lazy[pos]);
        if(l != r) {
            lazy[left(pos)] = lazy[pos];
            lazy[right(pos)] = lazy[pos];
        }
        lazy[pos] = 0;
    }

    void build(int pos, int l, int r, vector<T> &arr) {
        if(l == r) {
            tree[pos] = arr[l];
        } else {
            build(left(pos), l, mid(l, r), arr);
            build(right(pos), mid(l, r) + 1, r, arr);
            tree[pos] = combine(tree[left(pos)], tree[right(pos)]);
        }
    }

    T query(int pos, int l, int r, int L, int R) {
        lazyUpdate(pos, l, r);
        if(r < L || l > R || l > r) {
            return identity();
        }
        if(L <= l && r <= R) {
            return tree[pos];
        }
        T q1 = query(left(pos), l, mid(l, r), L, R);
        T q2 = query(right(pos), mid(l, r) + 1, r, L, R);
        return combine(q1, q2);
    }

    void update(int pos, int l, int r, int L, int R, int val) {
        lazyUpdate(pos, l, r);
        if(r < L || l > R || l > r) {
            return;
        }
        if(L <= l && r <= R) {
            lazy[pos] = val;
            lazyUpdate(pos, l, r);
            return;
        }
        update(left(pos), l, mid(l, r), L, R, val);
        update(right(pos), mid(l, r) + 1, r, L, R, val);
        tree[pos] = combine(tree[left(pos)], tree[right(pos)]);
    }

public:
    SegmentTree(vector<T> arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(0, 0, n - 1, arr);
    }

    T query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    void update(int l, int r, int val) {
        update(0, 0, n - 1, l, r, val);
    }
};

int main() {
    int t;
    string s;
    cin>>t;
    while(t--) {
        int n;
        cin>>s;
        n = s.size();
        int c = 0;
        vector<int>cnt, last(n + 1, 0), seen(n + 1, 0);
        for(int i = 0; i < n; i++){
            if(s[i] == '(')c++;
            else c--;
            cnt.push_back(c);
        }
        ll ans = 0;
        //SegmentTree st(cnt);
        SegmentTree<int> st(cnt);
        for(int i = 0; i < n; i++){
            if(st.query(last[cnt[i]], i) - cnt[i] <= cnt[i]){
                ans += seen[cnt[i]];
            } else seen[cnt[i]] = 0;
            last[cnt[i]] = i;
            seen[cnt[i]]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

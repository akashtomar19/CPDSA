#include <bits/stdc++.h>
using namespace std;
// #ifndef ONLINE_JUDGE
// #include "debugging.h"
// #endif
using ll = long long;

// BeginCodeSnip{HashedString}
class HashedString {
  private:
   // change M and B if you want
   static const ll M = (1LL << 61) - 1;
   static const ll B;
   // pow[i] contains B^i % M
   static vector<ll> pow;

   // p_hash[i] is the hash of the first i characters of the given string
   vector<ll> p_hash, r_hash;

   __int128 mul(ll a, ll b) { return (__int128)a * b; }
   ll mod_mul(ll a, ll b) { return mul(a, b) % M; }

  public:
   HashedString(const string &s) : r_hash(s.size() + 1), p_hash(s.size() + 1) {
      while (pow.size() < s.size()) { pow.push_back(mod_mul(pow.back(), B)); }
      p_hash[0] = 0;
      r_hash[0] = 0;
      for (int i = 0; i < s.size(); i++) {
         p_hash[i + 1] = (mul(p_hash[i], B) + s[i]) % M; // 1-based
      }
      ll sz = s.size();
      for (int i = sz - 1, j = 0; i >= 0; i --, j ++) {
         r_hash[j + 1] = (mul(r_hash[j], B) + s[i]) % M;
      }
   }

   ll getHash(int start, int end) { // 0 based 
      ll raw_val = p_hash[end + 1] - mod_mul(p_hash[start], pow[end - start + 1]);
      return (raw_val + M) % M;
   }
   ll getrHash(int start, int end) { // 0 based 
      ll raw_val = r_hash[end + 1] - mod_mul(r_hash[start], pow[end - start + 1]);
      return (raw_val + M) % M;
   }
};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
vector<ll> HashedString::pow = {1};
const ll HashedString::B = uniform_int_distribution<ll>(0, M - 1)(rng);
// EndCodeSnip
void solve () {
  int n, l, r;
  cin >> n >> l >> r;
  string s;
  cin >> s;
  HashedString st(s);
  vector < int > mem(n + 1, -1);
  for (int j = l; j <= r; j ++) {
    int lo = 1, hi = n, ans = 0;
    while (lo <= hi) {
      int m = (lo + hi) / 2;
      int cnt = 1;
      if (mem[m] != -1) {
        cnt = mem[m];
        goto down;
      }
      for (int i = m; i < n; i ++) {
        if (i + m - 1 >= n) break;
        if (st.getHash(0, m - 1) == st.getHash(i, i + m - 1)) {
          ++cnt;
          i += m - 1;
        }
      }
      mem[m] = cnt;
      down:
      if (cnt >= j) {
        ans = m;
        lo = m + 1;
      } else hi = m - 1;
    }
    cout << ans << " ";
  }
  cout << "\n";
}
signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc = 1;
  cin >> tc;
  while (tc --) {
    solve();
  }
}
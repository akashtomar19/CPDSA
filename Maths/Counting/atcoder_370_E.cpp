#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 998244353;

int32_t main(){
  int n,k;
  cin>>n>>k;
  int a[n + 1];
  for(int i = 1; i <= n; i++){
    cin>>a[i];
  }
  int tot = 1;
  map<int, int>m;
  m[0] = 1;
  int s = 0;
  int cur = 0;
  for(int i = 1; i <= n; i++){
    int bad = 0;
    s += a[i];

    if(m.count(s - k)){
        bad = m[s - k];
    }
    cur = tot - bad;
    cur += mod;
    cur %= mod;
    tot += cur;
    tot += mod;
    m[s] += cur;
    m[s] %= mod;
  }
  cout<<cur<<endl;
  return 0;
}

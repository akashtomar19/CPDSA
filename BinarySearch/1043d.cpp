#include<bits/stdc++.h>
#define int long long
using namespace std;
int cnt_digits(int n){
    int l = 1e18;
    int res = 0;
    while(l){
        if(n / l != 0){
            //cout<<n<<" "<<n/l<<" "<<l<<" "<<res<<endl;

            int a = n / l;
            int b = n % l;
            int c = a * l + b - l + 1;
            res += c;
           // n -= c;
            // cout<<res<<" "<<a<<" "<<b<<" "<<c<<endl;
            //cout<<res<<" "<<c<<" "<<a<<" "<<b<<endl;
        }
        l /= 10;
    }
    return res;
}
vector<vector<pair<int, int>>>dp;

pair<int, int> cnt(string& s, bool high, int j){

    if(j >= s.size())return {0, 1};

    pair<int, int>resp = {0, 0};

    if(dp[j][(int)high] != pair<int,int>{-1, -1})return dp[j][(int)high];

    if(high){
        for(int i = 0; i <= s[j] - '0'; i++){
            int cur = i;
            auto a = cnt(s, i == (s[j] - '0'), j + 1);
            resp.first += i * a.second;
            resp.second += a.second;
            resp.first += a.first;
        }
    } else {
        for(int i = 0; i <= 9; i++){
            int cur = i;
            auto a = cnt(s, false, j + 1);
            resp.first += i * a.second;
            resp.second += a.second;
            resp.first += a.first;
        }
    }

     return dp[j][high] = resp;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){

        int k;
        cin>>k;

        dp.clear();

        dp.resize(20, vector<pair<int,int>>(2, {-1, -1}));

        int l = 1;
        int r = 1e18;

        int res = 0;

        while(l <= r){
            int mid = (l + r) >> 1;
            int val = cnt_digits(mid);

            if(val < k){
                res = mid;

                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        //cout<<"print res "<<res<<endl;
        string ares = to_string(res);
        int a = cnt(ares, true, 0).first;

        int b = 0;

        k -= cnt_digits(res);
        string aa = to_string(res + 1);
        reverse(aa.begin(), aa.end());
        while(k -- ){
            b += (aa.back() - '0');
            aa.pop_back();
        }
        //cout<<b<<endl;
        cout<<b+a<<endl;
    }
}

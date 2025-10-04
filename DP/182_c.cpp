#include<vector>
#include<iostream>
#define int long long
using namespace std;

int mod = 998244353;

vector<vector<int> >dp;

int count(vector<int>&a, vector<int>&b, int i, bool isInverted){
    if(i == a.size())return 1;

    if(dp[i][isInverted] != -1)return dp[i][isInverted];
    

    int prea = isInverted ? b[i - 1] : a[i - 1];
    int preb = isInverted ? a[i - 1] : b[i - 1];

    // cout<<a[i]<<" "<<prea<<endl;
    // cout<<b[i]<<" "<<preb<<endl;

    int res = 0;

    if(a[i] >= prea and b[i] >= preb)res += count(a, b, i + 1, false);
    res %= mod;
    if(a[i] >= preb and b[i] >= prea)res += count(a, b, i + 1, true); 

    return dp[i][isInverted] = res % mod;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        dp.resize(n +1, vector<int>(2, -1));
        cout<<endl;

        // for(auto d: dp){
        //     for(auto c: d){
        //         cout<<c<<" # ";
        //     }
        //     cout<<endl;
        // }
        
        vector<int>a;
        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        vector<int>b;
        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            b.push_back(x);
        }
        int res = count(a, b, 1, true) + count(a, b, 1, false);
        // auto aa = a;
        // auto bb = b;
        // sort(a.begin(), a.end());
        // sort(b.begin(), b.end());
        // if(aa == a && bb == b)res -= 1;
        cout<<res % mod<<endl;
        dp.clear();
    }
}

// 1
// 5
// 2 3 3 4 4
// 1 1 3 5 6
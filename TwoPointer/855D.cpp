
#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin>>t;
    int res = 0;
    //map<pair<int, int>, int>mp;
    while(t--){
        res = 0;
        int n;
        cin>>n;
        string s;
        cin>>s;
        string pre = "##";
        int cnt = 0;
        for(int i = 2; i < s.size(); i++){
            string cur = string() + s[i] + s[i - 1];
            if(s[i] == s[i - 2]){
                cnt++;
                continue;
            }
            pre = cur;
        }
        //cout<<cnt<<endl;
        cout<<n - 1 - cnt<<endl;
    }

}

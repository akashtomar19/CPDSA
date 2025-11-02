


#include<vector>
#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;

        int cur = 9;
        int p = 1;
        int len = 1;

        while(len * cur * p < k){
            k -= len * cur * p;
            len++;
            p *= 10;
        }

        // lets go to the exact number

        int n = 0;

        if(len - 1 >= 0)n = pow(10, len - 1) - 1;

        int f = (k - 1) / len;
        int ss = (k - 1) % len;

        // cout<<" pre "<<n<<endl; 

        if(f)
        n += f;

        // cout<<k<<" "<<n<<" "<<len<<endl;
        // continue;

        string s = to_string(n + 1);

        int res = 0;

        for(int i = 0; i <= ss; i++){
            res += s[i] - '0';
        }
        // cout<<" yay "<<res<<" "<<endl;

        // continue;

        // sum up to 1 to n
        
        // n = 11;
        //  res = 0;

        // cout<<" hee "<<" "<<n<<endl;

        // cout<<" hee 1 "<<" "<<res<<endl;
        // res = 0;
        // n = 18;

        


        string s1 = to_string(n + 1);
        int prs = 0;
        for(int i = 0; i < s1.size(); i++){
            int curd = s1[i] - '0';
            if(curd){
                int l = s1.size() - i - 1;
                int f = curd * (l) * 45 * pow(10, max(l - 1, 1LL*0));
                int s = (prs * curd + curd * (curd - 1) / 2)  * pow(10, l);
                // cout<<f<<" "<<s<<endl;
                res += f + s;
                prs += curd;
            }
        }
        cout<<res<<endl;
    }
}

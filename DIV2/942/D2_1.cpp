#include<bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(18);
    int t;
    cin>>t;
    while(t--){

        int n, m;
        cin>>n>>m;
        int res = 0;

        for(int c = 1; c <= m; c++){
            for(int g = c; g <= m; g += c){
                for(int b = g; b <= m; b += g){

                    int b0 = b / g;
                    int a0 = g / c - b0;
                    if(a0 <= 0)break;

                    // if(gcd(a0, b0) != 1)continue;
                    if(a0 * g <= n and gcd(a0, b0) == 1)res++;


                }
            }
        }
        cout<<res<<'\n';
    }
}

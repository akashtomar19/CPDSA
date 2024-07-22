
// https://codeforces.com/contest/148/problem/D
#include<bits/stdc++.h>
#define double long double
using namespace std;
int x = 0;
double d[1001][1001];
double dfs(int ww, int bb){
    if(ww <= 0)return 0;
    if(bb <= 0)return 1;
    if(d[ww][bb] > 0){
        return d[ww][bb];
    }

//    cout<<ww<<bb<<endl;


    double ans = 1.0 * ww/(ww + bb);
    double w = ww;
    double b = bb;
    if(b + w - 2 <= 0)return ans;

     ans += (b/(b + w)) * ((b - 1)/(b + w - 1)) * (((b - 2)/(b + w - 2)) * dfs(ww, bb - 3) + (w/(b + w - 2)) * dfs(ww - 1, bb - 2));

     return d[ww][bb] = ans;
}
int main(){
    cout << fixed << setprecision(15);
    int w, b;
    cin>>w>>b;
    memset(d, 0, sizeof(d));
    cout<<dfs(w, b)<<endl;
}

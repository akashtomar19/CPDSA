#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int l = 1, r = 999;
        int res = -1;
        while(l <= r){
            int left = (2*l + r) / 3;
            int right = (2*r + l) / 3;
            cout<<"? "<<left<<" "<<right<<endl;
            int area;
            cin>>area;
            if(area == left * right){
                l = right + 1;
            } else if(area == (left) * (right + 1)){
                res = right;
                l = left + 1;
                r = right - 1;
            } else {
                res = left;
                r = left - 1;
            }
        }
        cout<<"! "<<res<<endl;
    }
}

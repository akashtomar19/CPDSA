#include<bits/stdc++.h>
using namespace std;
int main(){
    int x, y, z, mx, my, mz;
    int a[7];
    cin>>x>>y>>z>>mx>>my>>mz;
    for(int i = 1; i <= 6; i++){
        cin>>a[i];
    }
    int gs = 0;
    if(x < 0)gs += a[5];
    if(y < 0)gs += a[1];
    if(z < 0)gs += a[3];
    if(x > mx)gs += a[6];
    if(y > my)gs += a[2];
    if(z > mz)gs += a[4];
    cout<<gs<<endl;
}

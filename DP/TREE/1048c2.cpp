
#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
#define int long long
using namespace std;

int mod = 998244353;

int32_t main(){
    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        
        
        vector<vector<int> > a(n);


        int sumr = 0;
        int res = 0;

        
        
        for(int i = 0; i < n; i++){
            int x, y;
            cin>>x>>y;
            // a[i].push_back(static_cast<int>(2LL));
            a[i] =  {x + y, x, y};
            sumr += y;
            res += y - x;
        }

        sort(a.begin(), a.end()); 
        
        if(n % 2 == 0){
            for(int i = 0; i < n / 2; i++){
                sumr -= (a[i][0]);
            }
            cout<<res + sumr<<endl;
        } else {
            auto temp = sumr;
            int curx = -1;
            for(int i = 0; i < n / 2 + 1; i++ ){
                // one with maximum value of x 
                if(curx == -1 or a[curx][1] < a[i][1]){
                    curx = i;
                }
                if(i < n / 2)
                    sumr -= a[i][0];
            }
            //sumr += a[curx][1];
            auto res1 = res + sumr - a[n / 2][0] + a[curx][0] - a[curx][2]; /// this is first candidate

            curx = -1;

            for(int i = n / 2; i < n; i++){
                if(curx == -1 or a[curx][2]  > a[i][2]){
                    curx = i;
                }
            }
            auto res2 = max(res1, sumr + res - a[curx][2]);
            cout<<res2<<endl;
        }
        
    }
}


// 1
// 1 1000000000
// 200000

// 1 4 4 90 7 12  100 100  100 100 
// 5 + 86 = 91 + 3 = 94 + 195
// 96 + 99



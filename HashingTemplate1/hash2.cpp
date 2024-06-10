//https://codeforces.com/contest/1968/problem/G2
#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define ull unsigned ll
using namespace std;
const int mod=1e9+7;
int g;
int n,kl,kr;
int m;
char s[N];
ull s1[N],g1[N];
void haxh()
{
	s1[0]=1;
	for(int i=1;i<=n;i++)
	{
		s1[i]=s1[i-1]*mod;
		g1[i]=g1[i-1]*mod+s[i];
	}
}
ull geth(int l,int r){
   // cout<<l<<" "<<r<<endl;
    return g1[r]-g1[l-1]*s1[r-l+1];}
vector<int> E[N];
set<int>st;

int main(){
    int t;
    cin>>t;
    while(t--){
            st.clear();
        //int n;
        cin>>n;
         int l,r;
        cin>>l>>r;
        //string s;
        scanf("%s",s+1);
        haxh();
        int aa = geth(1,1);
        int bb = geth(1,2);
        //cout<<aa<<" "<<bb<<endl;
        for(int i = 1; i <= n; i++){
            int l = 1, r = n - i + 1;
            int mx = 0;
            //cout<<i<<endl;
            while(l <= r){
                //cout<<l<<" "<<r<<endl;
                assert(l >= 1 && l <= n);
                assert(r >= 1 and r <= n);
                int mid = (l + r) / 2;

                if(geth(1, mid) == geth(i, i + mid - 1)){
                    //cout<<2<<endl;
                    mx = mid;
                    l = mid + 1;
                } else r = mid - 1;
            }
            //cout<<mx<<" "<<i<<endl;
            E[mx].push_back(i);
        }
        for(int i = 1; i <= n; i++){
            //cout<<i<<"   **  ";
            for(auto e: E[i]){
                //cout<<e<<" * ";
            }
            //cout<<endl;
        }
        //cout<<1<<endl;
        vector<int>res(n + 1, 0);

        for(int i = n; i >= 1; i--){
            for(auto e: E[i]){
                st.insert(e);
            }
            E[i].clear();
            int pre =-1, cnt = 0;
            if(i == 2){
                //cout<<" hey "<<st.size()<<endl;
                for(auto e: st){
                    //cout<<e<<" # ";
                }
                //cout<<endl;
            }
            while(1){
                auto it = st.upper_bound(pre);
                if(it == st.end())break;
                cnt++;
                pre = *it + i - 1;
                if(i == 2){
                    //cout<<*it<<" & "<<pre<<" "<<cnt<<endl;
                }
            }
            //cout<<i<<" vv "<<cnt<<endl;
            res[cnt] = max(res[cnt], i);
        }
        for(int i = n - 1; i >= 1; i--){
            res[i] = max(res[i + 1], res[i]);
        }

        for(int i = l; i <= r; i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
}

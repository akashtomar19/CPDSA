
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<unsigned long long>a;
        random_device rd;
        mt19937_64 gen(rd());
        random_device rd2;
        mt19937_64 gen2(rd2() + 1);
        map<unsigned long long, unsigned long long> mapping, mapping2;
        set<unsigned long long> used = {0}, used2 = {0};
        
        for(int i = 1; i <= n; i++){
            unsigned long long random;
            unsigned long long x;
            cin>>x;
            a.push_back(x);
            if(mapping.count(x) == 0){
                random = gen();
                while(used.count(random)){
                    random = gen();
                }
                used.insert(random);
                mapping[x] = random;
            }
            if(mapping2.count(x) == 0){
                random = gen2();
                while(used2.count(random)){
                    random = gen2();
                }
                used2.insert(random);
                mapping2[x] = random;
            }

        }
        vector<unsigned long long>pref(n + 1, 0), pref2(n + 1, 0);
        for(int i = 1; i <= n; i++){
            auto cur = mapping[a[i - 1]];
            pref[i] = pref[i - 1] ^ cur;
            auto cur2 = mapping2[a[i - 1]];
            pref2[i] = pref2[i - 1] ^ cur2;

        }
        while(q--){
            int l, r;
            cin>>l>>r;
            auto p = pref[r] ^ pref[l - 1];
            auto p2 = pref2[r] ^ pref2[l - 1];
            if(p == 0 and p2 == 0){
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        }

    }
}

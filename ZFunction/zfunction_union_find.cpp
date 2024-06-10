//https://codeforces.com/contest/1968/problem/G2
#include<iostream>
#include<cassert>
using namespace std;
//Longest Common Prefix(s,s.substr(i)) O(|s|)
#include<vector>
#include<string>
vector<int>Zalgo(const string&s)
{
	vector<int>ret(s.size());
	if(s.empty())return ret;
	ret[0]=s.size();
	int i=1,j=0;
	while(i<s.size())
	{
		while(i+j<s.size()&&s[j]==s[i+j])j++;
		ret[i]=j;
		if(j==0)
		{
			i++;
			continue;
		}
		int k=1;
		while(i+k<s.size()&&k+ret[k]<j)ret[i+k]=ret[k],k++;
		i+=k;j-=k;
	}
	return ret;
}
#include<vector>
struct UF{
	int n;
	vector<int>parent,rank;
	UF(int n_=0):n(n_),parent(n_),rank(n_,1)
	{
		for(int i=0;i<n_;i++)parent[i]=i;
	}
	int find(int a){return parent[a]!=a?parent[a]=find(parent[a]):a;}
	bool same(int a,int b){return find(a)==find(b);}
	bool unite(int a,int b)
	{
		a=find(a),b=find(b);
		if(a==b)return false;
		parent[a]=b;
		rank[b]+=rank[a];
		return true;
	}
	int size(int a){return rank[find(a)];}
};
#include<bits/stdc++.h>
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N,L,R;
		string S;
		cin>>N>>L>>R>>S;
		vector<int>Z=Zalgo(S);
		int cnt[N + 1];
        vector<int>idx[N + 1];
        int ans[N + 1];
        memset(cnt, 0, sizeof(cnt));
        memset(ans, 0, sizeof(ans));
		//cout<<endl;
		for(int i=0;i<=N;i++)idx[i].clear();
		for(int i=0;i<N;i++)idx[Z[i]].push_back(i);
		UF uf(N+1);
		for(int f = 1; f <= N; f++){
            for(int id: idx[f - 1]){
                uf.unite(id, id + 1);
            }
            int id = 0;
            cnt[f] = 0;
            while(id < N){
                cnt[f]++;
                id = uf.find(id + f);
            }
		}
		for(int i = 1; i <= N; i++){
            //cout<<cnt[i]<<" ";
		}
	//	cout<<endl;
		int pos = 1;
		for(int i = N; i >= 1; i--){
            while(cnt[i] >= pos)ans[pos++] = i;
		}
		for(int i = L; i <= R; i++){
            cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
}

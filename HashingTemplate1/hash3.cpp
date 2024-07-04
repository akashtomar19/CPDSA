// https://codeforces.com/contest/1979/problem/D
// ref https://codeforces.com/contest/1979/submission/264481460
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
#define F first
#define S second
#define PB push_back
#define ret(msg) cout << msg << '\n'; return
#define rep(i,a,b) for(ll i = a; i < b; i++)
#define rrep(i,a,b) for(ll i = a; i >= b; i--)
#define iter(v) for(auto &el:v)
#define trav(a, v) for(auto&a:v)
#define all(x) x.begin(),x.end()
#define FAST cin.tie(0); cout.tie(0);ios_base::sync_with_stdio(0)
#define coutfloat cout << fixed << setprecision(16)

template<typename T> void print(T t, bool newln = true){
	cout << t;
	if(newln) cout << '\n';
	else cout << " ";
}
template<typename T> void print(vector<T> t){
	iter(t) print(el, false);
	cout << '\n';
}
template<typename T, typename U> void print(pair<T, U> t){
	print(t.F, false);
	print(t.S);
}
template<typename T> void read(T &t){
	cin >> t;
}
template<typename T> void read(vector<T> &t){
	iter(t) read(el);
}
template<typename T, typename U> void read(pair<T, U> &t){
	cin >> t.F >> t.S;
}
template<typename T, typename... Args> void read(T& t, Args&... args){
	read(t);
	read(args...);
}

//uses double hashing
struct substringHash {
    string s;
    vll pHash1, pHash2;

    ll p, m1, m2, n;
    vll p_pow1, p_pow2;

    substringHash(string &s_, bool randomise = true){
        p = 37;
        s = s_;
        n = s.size();

        //randomises the two modulo by default
        if(randomise){
        	//Setup
            mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
            uniform_int_distribution<ll> distrib(1e8, 1e9+100);
            m1 = distrib(rng);
            m2 = distrib(rng);
        } else {
            m1 = 1000005737;
            m2 = 1000000181;
        }

        initialise_p_pow();

        initialisePrefixHash(pHash1, m1);
        initialisePrefixHash(pHash2, m2);
    }

    void initialisePrefixHash(vll &pHash, ll m){
        pHash = vll(n, 0);
        ll hash_value = 0;
        ll ctr = 0;
        for(char c: s){
            hash_value = (hash_value*p + (c - '0' + 1)) % m;
            pHash[ctr] = hash_value;
            ctr++;
        }
    }

    void initialise_p_pow(){
        p_pow1 = vll(n+1, 1);
        rep(i,1,n+1){
            p_pow1[i] = (p_pow1[i-1]*p) % m1;
        }

        p_pow2 = vll(n+1, 1);
        rep(i,1,n+1){
            p_pow2[i] = (p_pow2[i-1]*p) % m2;
        }
    }

    ll computeHash(ll l, ll r, vll &pHash, ll m, vll &p_pow){
        ll res = pHash[r];
        if(l != 0) res -= ((pHash[l-1] % m)*(p_pow[r - l + 1] % m)) % m;
        return (res % m + m) % m;
    }

    pll getHash(ll l, ll r){
        pll res = {computeHash(l, r, pHash1, m1, p_pow1), computeHash(l, r, pHash2, m2, p_pow2)};
        return res;
    }

    pll combineHash(pll h1, pll h2, ll x){
        pll res = h1;
        res.F += h2.F * p_pow1[x] % m1;
        res.S += h2.S * p_pow2[x] % m2;
        res.F %= m1;
        res.S %= m2;
        return res;
    }
};

void solve(){
    ll n, k;
    cin>>n;
    cin>>k;
    string s;
    cin>>s;
    auto r = s;
    reverse(all(r));
    string a, b;
    for(int i = 0; i < s.size(); i++){
        if((i / k) % 2){
            a += '0';
            b += '1';
        } else {
            a += '1';
            b += '0';
        }
    }

    substringHash s1(s, false);
    substringHash r1(r, false);

    substringHash a1(a, false);
    substringHash b1(b, false);

    if(s1.getHash(0, n - 1) == a1.getHash(0, n - 1) || s1.getHash(0, n - 1) == b1.getHash(0, n - 1)){
        cout<<n<<endl;
        return;
    }

    for(int i = 0; i < n; i++){
        auto ph = s1.getHash(i, n - 1);
        auto rh = r1.getHash(n - i, n - 1);

        if(ph == a1.getHash(0, n - i - 1) and rh == a1.getHash(n - i, n - 1)){
            cout<<i<<endl;
            return;
        }
        if(ph == b1.getHash(0, n - i - 1) and rh == b1.getHash(n - i, n - 1)){
            cout<<i<<endl;
            return;
        }

    }
    cout<<-1<<endl;

}

int main(){
	FAST;
	int t; cin >> t;
	while(t--){
	    solve();
	}
	return 0;
}

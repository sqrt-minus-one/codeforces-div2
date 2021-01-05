#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(),c.end()
#define sz(x) (int)(x).size()
#define endl '\n'
#define mod 1e9 + 7
#define rep(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define repL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++) 
#define repR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define trav(x,a) for (auto& x: a)
using ll = long long int; 
using vi = vector<int>;
using pi = pair<int, int>;
#define F first
#define S second
#define pb push_back 
#define pob pop_back
#define read(a,n) rep(i,n) cin>>a[i]
#define read1(a,n) repL(i,1,n) cin>>a[i]
#define write(a,n,s) rep(i,n) cout<<a[i]<<s;
const int N = 100010;
const int MOD = 1e9+7;
const ll INF = 1e18;
void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        //freopen((name+".out").c_str(), "w", stdout);
    }
}

struct DSU{
    DSU(int n){
        this->n = n;
        lst = new vector<int>[n];
        parent = new int[n];
        for(int i = 0; i < n; i++){
            lst[i] = vector<int>(1,i);
            parent[i]=i;
        }
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (lst[a].size() < lst[b].size())
                swap(a, b);
            while (!lst[b].empty()) {
                int v = lst[b].back();
                lst[b].pop_back();
                parent[v] = a;
                lst[a].push_back (v);
            }
        }
    }
    int n;
    vector<int> *lst;
    int *parent;
    int find_set(int v){ return parent[v]; }
};
int main() 
{ 
    setIO();
    string s; cin>>s;
    int n=sz(s);
    DSU dsu(n+1);
    vi primes;
    bool is_prime[n+1];
    memset(is_prime,true,sizeof(is_prime));
    repL(i,2,n){
        if (is_prime[i]){
            primes.pb(i);
            for (int j = 2; j*i <= n; j++) is_prime[j*i] = false;
        }
    }
    repL(i,2,n){
        int x = i;
        trav(p, primes){
            if (x % p == 0) {
                dsu.union_sets(i, p);
            }
        }
    }
    char ans[n+1];
    
    return 0;
}
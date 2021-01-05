#include <bits/stdc++.h>
using namespace std;
#define N 1010
#define all(c) c.begin(),c.end()
#define endl '\n'
#define mod 1e9 + 7
#define rep(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define repL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++) 
#define repR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003 
typedef long long int ll; 
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define pb push_back 
#define pob pop_back
#define read(a,n) rep(i,n) cin>>a[i]
#define write(a,n,s) rep(i,n) cout<<a[i]<<s;

ll dp[20][4][2];
ll solve(string target){
    int n = target.length();
    rep(i,20) rep(j,4)rep(k,2) dp[i][i][k] = -1;
    rep(j,4){
        dp[n][j][0] = 1;
        dp[n][j][1] = 1;
    }
    repR(i,n-1,0){
        rep(cnt,4){
            if (cnt == 3){
                if (target[i] > '0') dp[i][cnt][0] = dp[i+1][cnt][1];
                else dp[i][cnt][0] = dp[i+1][cnt][0];

                dp[i][cnt][1] = dp[i+1][cnt][1];
            }
            else {
                if (target[i] == '0'){
                    dp[i][cnt][0] = dp[i+1][cnt][0];
                }
                else {
                    dp[i][cnt][0] = dp[i+1][cnt+1][0] + (target[i] - '0' - 1)*dp[i+1][cnt+1][1] + dp[i+1][cnt][1];
                }

                dp[i][cnt][1] = 9*dp[i+1][cnt+1][1] + dp[i+1][cnt][1];
            }
        }
    }
    return dp[0][0][0];
}

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int t; cin>>t;
    while (t--){
        ll l,r; cin>>l>>r;
        ll ans = solve(to_string(r)) - solve(to_string(l-1));
        cout<<ans<<endl;
    }
    return 0;
}
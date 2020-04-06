#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<cstdlib>//rand()
#define rep(i,a,b) for(register long long i = (a);i <= (b);++i)
#define per(i,a,b) for(register long long i = (a);i >= (b);--i)
typedef long long ll;
typedef unsigned long long ull;
using std::string;using std::cin;using std::cout;

ll n,w,s,dp[5505][5505],q[5555],p[5555],a[5555],l,r,ans;

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> n >> w >> s;
    rep(i,1,n) cin >> a[i];
    rep(i,0,n+1) rep(j,0,w+1) dp[i][j] = -1e16;
    dp[1][1] = a[1];
    rep(i,2,n){
        l = r = 1 , q[l] = dp[i-1][w] , p[l] = w;
        per(j,w,1){
            while(!(p[l] <= j+s-1 && p[l] >= j-1) && l <= r) ++l;
            while(!(q[r] >= dp[i-1][j-1]) && l <= r) --r;
            q[++r] = dp[i-1][j-1] , p[r] = j - 1;
            dp[i][j] = q[l] + j * a[i];
        }
    }

    ans = -1e16;
    rep(i,1,w) ans = std::max(ans,dp[n][i]);
    cout << ans << "\n";
    return 0;
}

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<cstdlib>//rand()
#define rep(i,a,b) for(register int i = (a);i <= (b);++i)
#define per(i,a,b) for(register int i = (a);i >= (b);--i)
typedef long long ll;
typedef unsigned long long ull;
using std::string;using std::cin;using std::cout;

int n,dp[1111][1111][2],a[1111],now,head,tail;
//dp[][][0] --- left   ||   dp[][][1] --- right
int mod = 19650827,ans;

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> n;
    rep(i,1,n) cin >> a[i];
    a[0] = a[n+1] = -1;
    dp[1][n][0] = dp[1][n][1] = 1;
    
    per(len,n,2){
        rep(i,1,n){
            int j = i + len - 1; if(j > n) break;

            now = a[i] , head = a[i+1] , tail = a[j];
            if(now < head) (dp[i+1][j][0] += dp[i][j][0]) %= mod;
            if(now < tail) (dp[i+1][j][1] += dp[i][j][0]) %= mod;

            now = a[j] , head = a[i] , tail = a[j-1];
            if(now > head) (dp[i][j-1][0] += dp[i][j][1]) %= mod;
            if(now > tail) (dp[i][j-1][1] += dp[i][j][1]) %= mod;
        }
    }

    //rep(i,1,n) rep(j,1,n) cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << " \n";

    rep(i,1,n) (ans += dp[i][i][0]) %= mod;
    cout << ans << "\n";

    return 0;
}

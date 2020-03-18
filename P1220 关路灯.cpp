#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<cstdlib>//rand()
typedef long long ll;
typedef unsigned long long ull;
using std::string;using std::cin;using std::cout;

int dp[55][55][2],a[55],sum[55][55],b[55],n,p;

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> n >> p;
    for(register int i = 1;i <= n;++i){
        cin >> a[i] >> b[i];
        b[i] += b[i-1];
    }

    for(register int i = 1;i <= n;++i){
        for(register int j = i;j <= n;++j){
            sum[i][j] = b[n] - b[j] + b[i-1];
            dp[i][j][0] = dp[i][j][1] = 1e9+9;
        }
    }
    dp[p][p][0] = dp[p][p][1] = 0;

    for(register int i = p;i >= 1;--i){
        for(register int j = p;j <= n;++j){
            if(i == p && j == p) continue;
            dp[i][j][0] = std::min(dp[i+1][j][0] + (a[i+1] - a[i]) * sum[i+1][j] , dp[i+1][j][1] + (a[j] - a[i]) * sum[i+1][j]),
            dp[i][j][1] = std::min(dp[i][j-1][1] + (a[j] - a[j-1]) * sum[i][j-1] , dp[i][j-1][0] + (a[j] - a[i]) * sum[i][j-1]);
        }
    }
    cout << std::min(dp[1][n][0] , dp[1][n][1]) << "\n";
    return 0;
}

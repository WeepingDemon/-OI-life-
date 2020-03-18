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

int n,h,l,r,dp[2001][2001],a[2222];

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    
    cin >> n >> h >> l >> r;
    for(register int i = 1;i <= n;++i){
        cin >> a[i];
    }
    dp[0][0] = 1;
    for(register int i = 1;i <= n;++i){
        for(register int j = 0;j < h;++j){
            if(dp[i-1][j] == 0) continue;
            int now = (j - 1 + a[i]) % h;
            dp[i][now] = std::max(dp[i][now] , dp[i-1][j] + (l <= now && now <= r));
            now = (now + 1) % h;
            dp[i][now] = std::max(dp[i][now] , dp[i-1][j] + (l <= now && now <= r));
        }
    }


    int maxx = 0;
    for(register int i = 0;i < h;++i){
        maxx = std::max(maxx , dp[n][i]); 
    }
    cout << maxx-1 << "\n";
    return 0;
}

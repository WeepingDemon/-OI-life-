#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<cstdlib>//rand()
#define rep(i,a,b) for(register long long i = (a);i <= (b);++i)
#define per(i,a,b) for(register long long i = (a);i >= (b);--i)
typedef long long ll;
typedef unsigned long long ull;
using std::string;using std::cin;using std::cout;

int n,a[555],dp[555][555];

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> n;
    rep(i,1,n) cin >> a[i];
    rep(i,0,n+1) rep(j,0,n+1) dp[i][j] = 1e9;
    rep(i,1,n){
        dp[i][i] = 1;
        if(a[i] == a[i + 1]) dp[i][i + 1] = 1;
        else dp[i][i + 1] = 2;
    }
    rep(len,2,n){
        rep(i,1,n - len + 1){
            int j = i + len;
            if(a[i] == a[j]) dp[i][j] = std::min(dp[i][j] , dp[i+1][j-1]);
            rep(k,i,j-1) dp[i][j] = std::min(dp[i][j] , dp[i][k] + dp[k+1][j]);
        }
    }
    cout << dp[1][n] << "\n";
    
    return 0;
}

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

int dp[55][55],n,a[55];
string str;

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> str;
    n = str.length();
    rep(i,1,n) a[i] = str[i-1] - 'A' + 1;
    rep(i,0,n+1) rep(j,0,n+1) 
        if(i == j && i != 0 && i != n+1) dp[i][j] = 1;
        else dp[i][j] = 0x7FFFFFFF;

    rep(len,2,n){
        rep(l,1,n){
            int r = l+len-1;
            if(r > n) break;
            if(a[l] == a[r]) dp[l][r] = std::min(dp[l][r-1] , dp[l+1][r]);
            else rep(i,l,r-1){
                dp[l][r] = std::min(dp[l][r] , dp[l][i] + dp[i+1][r]);
            }
        }
    }

    cout << dp[1][n] << "\n";
    
    return 0;
}

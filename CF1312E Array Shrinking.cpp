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

int n,a[555],dp[555][555],num[555][555];

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> n;
    for(register int i = 1;i <= n;++i){
        cin >> a[i];
    }
    for(register int i = 1;i <= n;++i){
        for(register int j = i;j <= n;++j){
            if(i == j) num[i][j] = a[i];
            dp[i][j] = j - i + 1;
        }
    }
    for(register int len = 2;len <= n;++len){
        for(register int i = 1,j = len;j <= n;++i,++j){
            for(register int k = i;k < j;++k){
                dp[i][j] = std::min(dp[i][j],dp[i][k]+dp[k+1][j]);
                if(dp[i][k] == dp[k+1][j] && dp[i][k] == 1 && num[i][k] == num[k+1][j]){
                    dp[i][j] = 1 , num[i][j] = num[i][k] + 1;
                }
            }
        }
    }
    cout << dp[1][n] << "\n";

    return 0;
}

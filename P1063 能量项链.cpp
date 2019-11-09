#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;using std::endl;
typedef long long ll;
typedef unsigned long long ull;
int a[105];
ll dp[105][105];
//dp[L][R]区间选择左闭又开，即头[l],尾[R]，选择[L,R-1]的珠子
int main(){

    freopen("in.in","r",stdin);

    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){cin >> a[i] ; a[n + i] = a[i];}

    for(int len = 2;len <= n;len++){//枚举阶段
        // cout << "LEN = " << len << endl;
        for(int i = 1;i + len <= 2 * n;i++){//枚举起点
            for(int k = 1;k < len;k++){//枚举断点
                dp[i][i+len] = std::max(dp[i][i+len] , dp[i][i+k] + dp[i+k][i+len] + a[i]*a[i+k]*a[i+len]);
                // cout << "NOW::dp[" << i << "][" << i+k << "] = " << dp[i][i+k] << " dp[" << i+k << "][" << i+len << "] = " << dp[i+k][i+len] << " " << a[i]*a[i+k]*a[i+len] << "\n";
            }
        }

        // for(int i = 1;i + len <= 2 * n;i++){
        //     cout << "dp[" << i << "][" << i+len << "] = " << dp[i][i+len] << "\n";
        // }
        // cout << "\n----OVER----\n";

    }
    ll ans = 0;
    for(int i = 1;i + n <= 2 * n;i++){
        ans = std::max(ans,dp[i][i+n]);
    }
    cout << ans;
    return 0;
}

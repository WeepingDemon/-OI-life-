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

int mod = 998244353,sum[101];
ll U,A,n,m,a[101][2002],dp_A[101][4004];

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> n >> m;
    rep(i,1,n) rep(j,1,m) scanf("%lld",&a[i][j]);
    rep(i,1,n) rep(j,1,m) sum[i] += a[i][j] , sum[i] %= mod;

    dp_A[0][0] = 1;

    U = 1;
    rep(i,1,n) U = (U * (sum[i] + 1)) % mod;
    --U;

    rep(now,1,m){
        std::memset(dp_A,0,sizeof(dp_A));
        dp_A[0][n] = 1;
        rep(i,1,n)
            rep(j,n-i,n+i)
                dp_A[i][j] = ( dp_A[i-1][j] + dp_A[i-1][j+1] * (sum[i] - a[i][now]) % mod + dp_A[i-1][j-1] * a[i][now] ) % mod;
        rep(i,n+1,2*n) A = (A + dp_A[n][i]) % mod;
    }
    
    cout << ((U - A) % mod + mod) % mod << "\n";
    return 0;
}

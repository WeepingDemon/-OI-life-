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

int mod = 998244353;
int dp[1111][40021],n,a[1111];
ll ans;

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> n;
    ans = n;
    for(register int i = 1;i <= n;++i){
      cin >> a[i];
    }
    for(register int i = 2;i <= n;++i){
      for(register int j = 1;j < i;++j){
        int delta = dp[j][ a[i] - a[j] + 20000 ] + 1;
        dp[i][ a[i] - a[j] + 20000 ] += delta , ans += delta;
        dp[i][ a[i] - a[j] + 20000 ] %= mod , ans %= mod;
      } 
    }
    cout << ans << "\n";
    return 0;
}

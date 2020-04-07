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

ll tree[4000010],ans,mod = 998244353,f[1000005];
int n,a[4000010];

inline ll lowerbit(ll x){return x & (-x);}

inline void add(ll p,ll x){
    while(p <= n){
        tree[p] += x;
        p += lowerbit(p);
    }
    return;
}

inline ll ask(ll p){
    ll ans = 0;
    while(p > 0){
        ans += tree[p];
        p -= lowerbit(p);
    }
    return ans;
}

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> n;
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) add(i,1);
    
    f[0] = 1;
    rep(i,1,n) f[i] = f[i-1] * i % mod; 
    
    rep(i,1,n){
        ans = (ans + (ask(a[i] - 1) * f[n - i])) % mod;
        add(a[i],-1);
    }
    cout << ans + 1 << "\n";
    return 0;
}

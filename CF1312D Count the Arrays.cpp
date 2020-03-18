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

int p = 998244353;

ll _power(int x,int P){
    if(P < 0) return 0;
    ll ans = 1 , base = x;
    x %= p;
    while(P){
        if(P & 1) ans = (ans * base) % p;
        base *= base , base %= p;
        P >>= 1;
    }
    return ans;
}

ll C(ll n,ll m){
    if(n < m) return 0;
    m = std::min(m,n - m);
    ll up = 1 , down = 1;
    for(register int i = 1;i <= m;++i){
        up *= n-i+1, up %= p;
        down *= i , down %= p;
    }
    return up * _power(down,p-2) % p;
}


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    int n , m;
    cin >> n >> m;
    ll ans = 0;
    if(n != 2) cout << (((n-2) * C(m,n-1) % p) * _power(2,n-3)) % p;
    else cout << 0;
    return 0;
}

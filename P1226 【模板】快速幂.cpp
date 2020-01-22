#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
//int[1e7] ll[5*1e6]
typedef long long ll;
typedef unsigned long long ull;
using std::string;using std::cin;using std::cout;

ll mod;

inline int _pow(ll x,ll p){
    ll ans = 1 , base = x;
    while(p){
        if(p & 1) ans *= x , ans %= mod;
        x *= x ,x %= mod;
        p >>= 1;
    }
    return ans % mod;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    ll x,y;
    cin >> x >> y >> mod;
    cout << x << "^" << y << " mod " << mod << "=" << _pow(x,y) << "\n";
    return 0;
}

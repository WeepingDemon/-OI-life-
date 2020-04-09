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
using std::map;

ll n,a[222222],sum[222222],ans,last;

map<ll,ll> mp;


int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> n;
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) sum[i] = sum[i-1] + a[i];

    mp[0] = 0;

    rep(i,1,n){
        if(mp.count(sum[i]) > 0) last = std::max(last , mp[ sum[i] ] + 1);
        ans += i - last , mp[ sum[i] ] = i;
    }
    
    cout << ans << "\n";
    return 0;
}

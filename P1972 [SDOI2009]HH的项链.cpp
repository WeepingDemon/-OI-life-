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

ll n,m,a[1111111],p[1111111],cnt,now = 1,ans[1111111];
ll tree[4444444];

struct NODE{
    ll l,r,pos;
}b[1111111];

inline bool cmp(NODE x,NODE y){return x.r < y.r;}

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
    cin >> n ;
    rep(i,1,n) cin >> a[i];
    cin >> m;
    rep(i,1,m) cin >> b[i].l >> b[i].r;
    rep(i,1,m) b[i].pos = i;
    std::sort(b+1,b+m+1,cmp);
    
    rep(i,1,n) add(i,0);

    rep(i,1,n){
        if(p[ a[i] ] == 0){
            p[ a[i] ] = i;
            add(i,1);
        } else {
            add(p[ a[i] ],-1);
            p[ a[i] ] = i;
            add(i,1);
        }
        while(b[now].r == i){
            ans[ b[now].pos ] = ask(b[now].r) - ask(b[now].l-1);
            ++now;
        }
    }
    
    rep(i,1,m) cout << ans[i] << "\n";

    return 0;
}

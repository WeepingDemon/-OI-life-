#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
typedef long long ll;
using std::cin;using std::cout;using std::endl;

ll n,m,tree[2000010];

ll lowerbit(ll x){return x&(-x);}

ll ask(ll p){
    ll ans = 0;
    while(p > 0){
        ans += tree[p];
        p -= lowerbit(p);
    }
    return ans;
}//区间和查询1~p

void add(ll p,ll x){
    while(p <= n){
        tree[p] += x;
        p += lowerbit(p);
    }
}//单点加法

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int p = 1;p <= n;p++){
        ll x;
        cin >> x;
        add(p,x);
    }
    ll opt,a,b;
    for(int i = 1;i <= m;i++){
        cin >> opt >> a >> b;
        if(opt == 1) add(a,b);
        else cout << ask(b) - ask(a-1) << "\n";
    }
    return 0;
}

#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cmath>
#include<queue>
//int[1e7] ll[5*1e6]
using std::cin;using std::cout;using std::endl;
typedef long long ll;
typedef unsigned long long ull;
ll st[22222],ed[22222];

bool cmp(ll a,ll b){return a < b;}

int main(){
    // freopen("in.in", "r", stdin);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> st[i] >> ed[i];
    }
    std::sort(st+1,st+n+1,cmp);
    std::sort(ed+1,ed+n+1,cmp);
    ll ans = 0,op = -1e9,ov = 0;
    for(int i = 1;i <= n;i++){
        op = std::max(op,st[i]);
        ov = ed[i];
        // printf("op = %d , ov = %d \n",op,ov);
        ans += ov-op;
        op = ov;
    }
    cout << ans;
    return 0;
}

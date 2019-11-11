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

ll a[500010],ans;
ll b[500010];
void mergesort(ll l,ll r){
    if(l == r) return;
    ll mid = (l+r) >> 1;
    mergesort(l,mid) , mergesort(mid+1,r);
    ll i = l , j = mid+1 , p = l;
    while(i <= mid && j <= r){
        if(a[i] <= a[j]) b[p++] = a[i++];
        else b[p++] = a[j++] , ans += mid-i+1;
    } 
    while(i <= mid) b[p++] = a[i++];
    while(j <= r) b[p++] = a[j++];
    for(ll i = l;i <= r;i++) a[i] = b[i];
}

void solve(ll n){
    ans = 0;
    for(ll i = 1;i <= n;i++) cin >> a[i];
    mergesort(1,n);
    printf("%lld\n",ans);
}

int main(){
    ll n;
    while(cin>>n && n) solve(n);
    return 0;
}

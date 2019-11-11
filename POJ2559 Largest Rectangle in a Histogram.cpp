#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
//int[1e7] ll[5*1e6]
using std::cin;using std::cout;using std::endl;
typedef long long ll;
typedef unsigned long long ull;
ll n,stack[100010],wi[100010],top;
ll ans;
int main(){
    #ifdef LOCAL
    freopen("in.in", "r", stdin);
    #endif
    while(1){
        ans = 0 , top = 0;
        scanf("%lld",&n);ll x;
        if(n == 0) break;
        for(int i = 1;i <= n;i++){
            scanf("%lld",&x);
            if(x >= stack[top]) stack[++top] = x , wi[top] = 1;
            else{
                // cout << top << endl;
                ll cnt = 0;
                while(stack[top] > x){
                    cnt += wi[top];
                    ans = std::max(ans,stack[top]*cnt);
                    stack[top] = x;
                    top--;
                }
                stack[++top] = x;
                wi[top] = cnt+1;
                // cout << wi[top] << endl;
            }
        }
        x = 0;
        ll cnt = wi[top];
        while(stack[top] > x){
            ans = std::max(ans,stack[top]*cnt);
            top--,cnt += wi[top];
        }
        printf("%lld\n",ans);
    }
    return 0;
}

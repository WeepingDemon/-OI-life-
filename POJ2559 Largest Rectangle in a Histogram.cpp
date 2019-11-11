#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;using std::endl;
typedef long long ll;
ll n,stack[100010],wi[100010],top;
ll ans;
int main(){
    #ifdef LOCAL
    freopen("in.in", "r", stdin);
    #endif
    while(1){
        scanf("%lld",&n);ll x;
        if(n == 0) break;
        ans = 0 , top = 0;//初始化
        for(int i = 1;i <= n;i++){
            scanf("%lld",&x);
            if(x >= stack[top]) stack[++top] = x , wi[top] = 1;//符合单调性质，直接插入，宽度为1
            else{
                ll cnt = 0;//cnt维护被推出的元素的宽度
                while(stack[top] > x){//直到可以符合性质
                    cnt += wi[top];//将被推出的节点的宽度更新
                    ans = std::max(ans,stack[top]*cnt);//更新答案
                    top--;//推出
                }
                stack[++top] = x;//满足性质后插入元素
                wi[top] = cnt+1;//将被推出的节点更新后直接合并到新插入元素中
            }
        }
        x = 0;//类比先前插入，需要把所有余下元素推出，则相当于需要插入一个比所有元素都小的元素
        ll cnt = 0;
        while(stack[top] > x){
            cnt += wi[top];
            ans = std::max(ans,stack[top]*cnt);
            top--;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

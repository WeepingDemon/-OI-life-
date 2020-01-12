#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
//int[1e7] ll[5*1e6]
typedef long long ll;
typedef unsigned long long ull;
using std::cin;using std::cout;using std::endl;
//tmp存储前驱的连续括号对数，ans存储答案，搜索过程中注意复原局面。

char str[500005];
int stack[500005],top,head[500005],ver[500005],next[500005],tot,n,fa[500005];
ll ans[500005],tmp[500005];
inline void add(register int x,register int y){ver[++tot] = y , next[tot] = head[x] , head[x] = tot;}

inline void dfs(register int now){
    bool flg = false;ll TMP;
    if(str[now] == '('){
        tmp[++top] = ans[ fa[now] ] - ans[ fa[fa[now]] ];
        ans[now] = ans[ fa[now] ];//继承
        // stack[top] = now;
    } else {
        if(top > 0){
            flg = true;
            TMP = tmp[top];
            ans[now] = ans[ fa[now] ] + tmp[top--] + 1;//更新
        } else {
            ans[now] = ans[ fa[now] ];//继承
        }
    }

    for(register int i = head[now];i;i = next[i]) dfs(ver[i]);//往后搜

    //复原局面
    if(str[now] == '(') --top;
    else if(flg) tmp[++top] = TMP;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("in.in", "r", stdin);
    #endif
    cin >> n >> (str+1);
    for(register int i = 2;i <= n;i++){
        cin >> fa[i];
        add(fa[i],i);
    }
    dfs(1);
    for(register int i = 1;i <= n;i++){
        ans[0] ^= ans[i] * i;
    }
    cout << ans[0];
    return 0;
}

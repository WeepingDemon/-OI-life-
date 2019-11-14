#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
//int[1e7] ll[5*1e6]
typedef long long ll;
typedef unsigned long long ull;
using std::cin;using std::cout;using std::endl;

int tot,MT,n,m,s,head[1000010],ver[1000010],next[1000010],fa[1000010][20],dis[1000010];

void add(int x,int y){ver[++tot] = y , next[tot] = head[x] , head[x] = tot;}

void dfs(int now,int father){
    dis[now] = dis[father] + 1;
    fa[now][0] = father;
    
    for(int i = head[now];i;i = next[i]){
        if(ver[i] != father) dfs(ver[i],now);
    }
}

int LCA(int x,int y){
    if(dis[x] > dis[y]) std::swap(x,y);

    for(int i = MT;i >= 0;i--){
        if(dis[fa[y][i]] >= dis[x]) y = fa[y][i];
    }

    if(x == y) return x;

    for(int i = MT;i >= 0;i--){
        if(fa[x][i] != fa[y][i]) x = fa[x][i] , y = fa[y][i];
    }

    return fa[x][0];
}

int main(){
    #ifdef LOCAL
    freopen("in.in", "r", stdin);
    #endif

    scanf("%d%d%d",&n,&m,&s);
    for(int i = 1;i < n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y) , add(y,x);
    }

    MT = (int)(std::log(n)/std::log(2)) + 1;

    dfs(s,0);
    for(int i = 1;i <= MT;i++){
        for(int j = 1;j <= n;j++){
            fa[j][i] = fa[fa[j][i-1]][i-1];
        }
    }

    for(int i = 1;i <= m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",LCA(x,y));
    }

    // for(int i = 0;i <= n;i++){
    //     for(int j = 0;j <= 5;j++){
    //         printf("fa[%d][%d] = %d  ",i,j,fa[i][j]);
    //     }
    //     cout << endl;
    // }

    return 0;
}

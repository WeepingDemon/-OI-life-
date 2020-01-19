#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
//int[1e7] ll[5*1e6]
typedef long long ll;
typedef unsigned long long ull;
using std::cin;using std::cout;

int n,m,x,y,t,cnt,fa[1010],ans;

struct node{
    int st,to,t;
}edge[100010];

inline int getfa(int x){
    if(fa[x] == x) return x;
    else return fa[x] = getfa(fa[x]);
}

inline bool cmp(node a,node b){return a.t < b.t;}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    
    cin >> n >> m; 
    for(int i = 1;i <= n;++i) fa[i] = i;
    for(int i = 1;i <= m;++i){
        cin >> x >> y >> t;
        edge[++cnt].st = x , edge[cnt].to = y , edge[cnt].t = t;
    }

    std::sort(edge+1,edge+m+1,cmp);
    
    for(int i = 1;i <= m;++i){
        int a = edge[i].st , b = edge[i].to;
        fa[a] = getfa(fa[a]) , fa[b] = getfa(fa[b]);
        if(fa[a] != fa[b]){
            fa[fa[a]] = fa[b] , --n;
            if(n == 1){cout << edge[i].t;return 0;}
        } else {
            continue;
        }
    }
    cout << -1;
    return 0;
}

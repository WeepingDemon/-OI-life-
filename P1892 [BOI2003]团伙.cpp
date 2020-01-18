#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
//int[1e7] ll[5*1e6]
typedef long long ll;
typedef unsigned long long ull;
using std::cin;using std::cout;

int fa[2020],e[2020],n,m,ans; 
bool flg[1010];

inline int getfa(register int x){
    if(fa[x] == x) return fa[x];
    else return fa[x] = getfa(fa[x]);
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> n >> m;
    char opt;int x,y;
    for(register int i = 1;i <= n;++i){
        fa[i] = i;
    }
    for(register int i = 1;i <= m;++i){
        cin >> opt >> x >> y;
        if(opt == 'E'){
            if(e[x] == 0 && e[y] == 0){e[x] = y , e[y] = x;continue;}
            else if(e[x] != 0) x = e[x];
            else y = e[y];
        } 
        fa[x] = getfa(fa[x]) , fa[y] = getfa(fa[y]);
        fa[fa[x]] = fa[y];
        // cout << fa[x] << " " << y << "\n"; 
    }

    for(register int i = 1;i <= n;++i){
        fa[i] = getfa(fa[i]);
    }
    for(register int i = 1;i <= n;++i){
        if(flg[fa[i]] == false) ++ans , flg[fa[i]] = true;
    }
    cout << ans << "\n";
    return 0;
}

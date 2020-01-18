#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
//int[1e7] ll[5*1e6]
typedef long long ll;
typedef unsigned long long ull;
using std::cin;using std::cout;

int fa[150005],n,k,opt,x,y,ans;
//fa[x+n] ~ food                fa[x+2*n] ~ hunter

inline int getfa(int x){
    if(x == fa[x]) return x;
    else return fa[x] = getfa(fa[x]);
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> n >> k;
    for(register int i = 1;i <= 3 * n;++i) fa[i] = i;
    while(k--){
        cin >> opt >> x >> y;
        if(std::max(x,y) > n){++ ans;continue;}
        
        for(register int j = 0;j <= 2;++j) fa[x + j * n] = getfa(fa[x + j * n]) , fa[y + j * n] = getfa(fa[y + j * n]); 
        
        if(opt == 1){
            if(fa[x + n] == fa[y] || fa[x + 2 * n] == fa[y]){++ ans;continue;}
            fa[fa[x]] = fa[y] , fa[fa[x + n]] = fa[y + n] , fa[fa[x + 2 * n]] = fa[y + 2 * n];
        } else {
            if(fa[x] == fa[y] || fa[x + 2 * n] == fa[y]){++ ans;continue;}
            fa[fa[x + n]] = fa[y] , fa[fa[x + 2 * n]] = fa[y + n] , fa[fa[y + 2 * n]] = fa[x]; 
        }
    }
    cout << ans << "\n";

    return 0;
}

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
//int[1e7] ll[5*1e6]
typedef long long ll;
typedef unsigned long long ull;
using std::cin;using std::cout;

int n,m,p,q,fa[20020],b = 10005,x,y,A,B;

inline int getfa(int x){
    if(fa[x + b] == x ) return x;
    else return fa[x + b] = getfa(fa[x + b]);
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> n >> m >> p >> q;
    
    //fa[x] = x
    for(register int i = -m-5;i <= n+5;++i){
        if(i == 0) continue;
        fa[b + i] = i;
        //cout << fa[i + b] << " ";
    }
    for(register int i = 1;i <= p;++i){
        cin >> x >> y;
        fa[x + b] = getfa(fa[x + b]) , fa[y + b] = getfa(fa[y + b]);
        fa[fa[x + b] + b] = fa[y + b];
    }
    for(register int j = 1; j <= q;++j){
        cin >> x >> y;
        fa[x + b] = getfa(fa[x + b]) , fa[y + b] = getfa(fa[y + b]);
        fa[fa[x + b] + b] = fa[y + b];
    }
    fa[1+b] = getfa(fa[1+b]) , fa[b-1] = getfa(fa[b-1]);
    for(register int i = -m;i <= n;++i){
        if(i == 0) continue;
        fa[i + b] = getfa(fa[i + b]);
        if(fa[i + b] == fa[b-1]) ++B;
        else if(fa[i + b] == fa[b+1]) ++A;
    }
    cout << std::min(A,B) << "\n";
    return 0;
}

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
//int[1e7] ll[5*1e6]
typedef long long ll;
typedef unsigned long long ull;
using std::string;using std::cin;using std::cout;

int t,x,y,Fx,Fy,fa[30010],num[30010],dis[30010];
char opt;

inline int getfa(int x){
    if(x == fa[x]) return x;
    else{
        int fx = fa[x];
        fa[x] = getfa(fa[x]);
        dis[x] += dis[fx] , num[x] = num[fa[x]];
        return fa[x];
    }
}

inline void update(){
    if(Fx == Fy) return;
    dis[Fx] = dis[Fy] + num[Fy];
    fa[Fx] = Fy;
    num[ Fy ] = num[ Fx ] = num[ Fx ]  + num[ Fy ];
}

inline void query(){
    if(Fx == Fy){
        cout << std::abs(dis[y] - dis[x]) - 1 << "\n";
    } else {
        cout << -1 << "\n";
    }
    return ;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    for(register int i = 1;i <= 30000;++i){
        fa[i] = i , num[i] = 1 , dis[i] = 0;
    }

    cin >> t;
    while(t--){
        cin >> opt >> x >> y;
        Fx = getfa(x) , Fy = getfa(y);
        if(opt == 'M'){
            update();
        } else {
            query();
        }
    }
    return 0;
}

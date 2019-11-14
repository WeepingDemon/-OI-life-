#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using std::cin;using std::cout;using std::endl;
ll n,m,s;
ll head[222222],ver[222222],next[222222],edge[222222],tot;
ll dis[222222];
bool flg[222222];
std::priority_queue< std::pair<ll,ll> > q;

inline void link(ll x,ll y,ll z){ver[++tot] = y , edge[tot] = z , next[tot] = head[x] , head[x] = tot;}

inline void dijkstra(){
    q.push(std::make_pair(0,1));
    while(q.size()){
        ll x = q.top().second; q.pop();
        if(flg[x]) continue;
        flg[x] = true;
        for(ll i = head[x];i;i = next[i]){
            ll y = ver[i] , z = edge[i];
            if(dis[y] > dis[x] + z){
                dis[y] = dis[x] + z;
                q.push(std::make_pair(-dis[y],y));
            }
        }
    }
}

int main(){
    #ifdef LOCAL
    freopen("in.in", "r", stdin);
    #endif
    scanf("%d%d%lld",&n,&m,&s);
    ll u,v,w;
    for(register int i = 1;i <= m;i++){
        scanf("%lld%lld%lld",&u,&v,&w);
        link(u,v,w);
    }
    for(register int i = 1;i <= n;i++) dis[i] = 1000000009;
    dis[s] = 0;
    dijkstra();
    for(register int i = 1;i <= n;i++) printf("%d ",dis[i]);
    return 0;
}

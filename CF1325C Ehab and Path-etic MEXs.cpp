#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<cstdlib>//rand()
typedef long long ll;
typedef unsigned long long ull;
using std::string;using std::cin;using std::cout;

int t[222222],u[222222],v[222222],node = -1,ppp,qqq = 3;

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    int n;
    cin >> n;
    for(register int i = 1;i < n;++i){
        cin >> u[i] >> v[i];
        ++t[ u[i] ] , ++t[ v[i] ];
        
        if(t[u[i]] >= 3 && node == -1){
            node = u[i];
        } else if(t[v[i]] >= 3 && node == -1){
            node = v[i];
        }
    }

    if(node == -1){
        for(register int i = 1;i < n;++i){
            cout << i-1 << "\n";
        }
        return 0;
    }

    for(register int i = 1;i < n;++i){
        if(ppp <= 2 && (u[i] == node || v[i] == node)){
            cout << ppp++ << "\n";
            continue;
        }
        cout << qqq++ << "\n";
        
    }
    return 0;
}

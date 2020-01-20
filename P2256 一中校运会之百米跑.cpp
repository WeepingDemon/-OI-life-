#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
//int[1e7] ll[5*1e6]
typedef long long ll;
typedef unsigned long long ull;
using std::cin;using std::cout;using std::string;

std::map<string,string> fa;

string x,y;

int n,m;

inline string getfa(string p){
    if(p == fa[p]) return p;
    else return fa[p] = getfa(fa[p]);
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(register int i = 1;i <= n;++i){
        cin >> x;
        fa[x] = x;
    }
    for(register int i = 1;i <= m;++i){
        cin >> x >> y;
        fa[x] = getfa(fa[x]) , fa[y] = getfa(fa[y]);
        fa[fa[x]] = fa[y];
    }
    cin >> m;
    for(register int i = 1;i <= m;++i){
        cin >> x >> y;
        fa[x] = getfa(fa[x]) , fa[y] = getfa(fa[y]);
        if(fa[x] == fa[y]) cout << "Yes.\n";
        else cout << "No.\n";
    }

    return 0;
}

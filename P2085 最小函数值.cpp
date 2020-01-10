#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
//int[1e7] ll[5*1e6]
typedef long long ll;
typedef unsigned long long ull;
using std::cin;using std::cout;

int inf = 1e9;

int n,m,a[10010],b[10010],c[10010],step[10010],lim,tj;

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(register int i = 1;i <= n;++i){
        cin >> a[i] >> b[i] >> c[i];
        step[i] = 1;
    }

    for(register int i = 1;i <= m;++i){
        lim = inf;
        for(register int j = 1;j <= n;++j){
            lim = lim < (a[j] * step[j] * step[j] + b[j] * step[j] + c[j]) ? lim : (a[j] * step[j] * step[j] + b[j] * step[j] + c[j]);
            if(lim == (a[j] * step[j] * step[j] + b[j] * step[j] + c[j]) ) tj = j; 
        }
        ++step[tj];
        // cout << "debug : : " << step[tj] << " ";
        cout << lim << " ";
    }
    return 0;
}

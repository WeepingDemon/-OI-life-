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

ll n,a[222222],maxx,b[222222];

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> n;
    for(register int i = 1;i <= n;++i){
        cin >> a[i];
        b[i] = a[i] + std::max(b[i-1],maxx);
        maxx = std::max(maxx,b[i]);
    }
    for(register int i = 1;i <= n;++i){
        cout << b[i] << " ";
    }

    return 0;
}

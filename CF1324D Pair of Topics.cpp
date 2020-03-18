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

ll n,a[222222],ans,tmp;
inline bool cmp1(int x,int y){return x < y;}
inline bool cmp2(int x,int y){return x > y;}

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    
    cin >> n;
    for(register int i = 1;i <= n;++i){
        cin >> a[i];
    }
    int x;
    for(register int i = 1;i <= n;++i){
        cin >> x;
        a[i] -= x , a[i] = -a[i];
    }
    std::sort(a+1,a+n+1,cmp1);

    for(register int i = 1;i <= n;++i){
        tmp = std::lower_bound(a+1,a+n+1,-a[i]) - a - 1;
        ans += tmp;
        if(a[i] < 0) --ans;
    }
    cout << (ans / 2) << "\n";


    return 0;
}

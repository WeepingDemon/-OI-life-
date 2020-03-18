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

int n,k,maxx;
ll a[10000],x;

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    
    int T;
    cin >> T;
    while(T--){
        bool flag = false;
        cin >> n >> k;
        for(register int i = 1;i <= n;++i){
            cin >> x;
            int p = 0;
            while(x){
                a[++p] += x % k , x /= k;
                if(a[p] > 1) flag = true;
            }
            maxx = maxx > p ? maxx : p;
        }

        if(flag) cout << "NO\n";
        else cout << "YES\n";

        for(register int i = 1;i <= maxx;++i){
            a[i] = 0;
        }
    }

    return 0;
}

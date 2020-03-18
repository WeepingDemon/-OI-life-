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

ll n,m,a[222222],ans = 1;

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(register int i = 1;i <= n;++i){
        cin >> a[i];
    }
    if(n > m){
        cout << 0 << "\n";
        return 0;
    } else {
        for(register int i = 1;i < n;++i){
            for(register int j = i + 1;j <= n;++j){
                ans = ((ans % m) * std::abs(a[i] - a[j]) % m) % m;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}

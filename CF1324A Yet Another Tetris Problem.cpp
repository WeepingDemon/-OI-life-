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

int n,a[111],max;
bool flag;

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    
    int T;
    cin >> T;
    while(T--){
        flag = true;
        cin >> n;
        for(register int i = 1;i <= n;++i){
            cin >> a[i];
            max = std::max(a[i],max);
        }
        for(register int i = 1;i <= n;++i){
            a[i] = max - a[i];
            a[i] %= 2;
        }
        for(register int i = 2;i <= n;++i){
            if(a[i] != a[i-1]){
                flag = false;
                break;
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";

        
    }

    return 0;
}

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

int n,a[55555];

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    
    int T;
    cin >> T;
    while(T--){
        bool flag = false;
        cin >> n;
        for(register int i = 1;i <= n;++i){
            cin >> a[i];
        }
        for(register int i = 1;i <= n;++i){
            for(register int j = n;j > i+1;--j){
                if(a[i] == a[j] && j-i >= 2){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

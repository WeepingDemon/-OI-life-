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

ll n,a[111111],k;

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(register int i = 1;i <= n;++i){
            cin >> a[i];
        }
        k = n;
        std::sort(a+1,a+n+1);

        for(register int i = 2;i <= n;++i){
            if(a[i] == a[i-1]){
                --k;
            }
        }
        cout << k << "\n";

    }

    return 0;
}

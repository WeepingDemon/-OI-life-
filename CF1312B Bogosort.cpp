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

inline bool cmp(int x,int y){
    return x > y;
}

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    
    int T;
    cin >> T;
    while(T--){
        int n , a[111];
        cin >> n;
        for(register int i = 1;i <= n;++i){
            cin >> a[i];
        }
        std::sort(a+1,a+n+1,cmp);
        for(register int i = 1;i <= n;++i){
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}

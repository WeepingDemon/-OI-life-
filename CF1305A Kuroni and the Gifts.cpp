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

int a[101],b[101];

inline bool cmp(int x,int y){return x < y;}

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    
    int T,n;
    cin >> T;
    while(T--){
        cin >> n;
        for(register int i = 1;i <= n;++i){
            cin >> a[i];
        }  
        for(register int i = 1;i <= n;++i){
            cin >> b[i];
        }
        std::sort(a+1,a+n+1,cmp) , std::sort(b+1,b+n+1,cmp);

        for(register int i = 1;i <= n;++i){
            cout << a[i] << " ";
        }cout << "\n";
        for(register int i = 1;i <= n;++i){
            cout << b[i] << " ";
        }cout << "\n";
    }

    return 0;
}

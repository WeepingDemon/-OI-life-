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



int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    
    int T,x,y;
    cin >> T;
    while(T--){
        cin >> x >> y;
        if(x % y == 0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

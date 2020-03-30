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

int x,y,ans;

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    int T;
    cin >> T;
    while(T--){
        ans = 0;
        cin >> x >> y;
        x = x % y;
        if(x == 0) cout << x << "\n";
        else cout << y-x << "\n";
    }
    

    return 0;
}

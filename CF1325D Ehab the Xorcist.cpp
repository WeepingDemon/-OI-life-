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

ll x,y,z,p;

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    
    cin >> x >> y;
    if(x > y){cout << "-1\n";return 0;}
    else if(x == 0 && y == 0){cout << "0\n";return 0;}
    else if(x == y){
        cout << 1 << " " << x << "\n";
        return 0;
    }
    z = y - x;
    if(z & 1){cout << -1 << "\n";return 0;}
    else {
        z >>= 1;
        if(z + x == (z ^ x)){
            cout << 2 << "\n" << z << " " << (z ^ x) << "\n";
        } else {
            cout << 3 << "\n" << x << " " << z << " " << z << "\n";
        }
    }


    return 0;
}

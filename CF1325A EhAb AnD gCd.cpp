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

int x;

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    
    int T;
    cin >> T;
    while(T--){
        cin >> x;
        if(x == 2) cout << "1 1\n"; 
        else if(x % 2) cout << 1 << " " << x-1 << "\n";
        else cout << 2 << " " << x-2 << "\n";
    }

    return 0;
}

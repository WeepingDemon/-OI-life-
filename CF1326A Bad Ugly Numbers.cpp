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
    int T,n;
    cin >> T;
    while(T--){
        cin >> n;
        if(n == 1) cout << "-1\n";
        else if(n == 2) cout << "23\n";
        else {
            for(register int i = 1;i <= n-2;++i){
                cout << "2";
            }
            if((n-1)%3) cout << "23\n";
            else cout <<  "33\n";
        }
    }
    

    return 0;
}

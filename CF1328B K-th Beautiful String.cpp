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

ll n,k,x,y;

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);

    int T;
    cin >> T;
    while(T--){
        cin >> n >> k;
        x = 0 , y = 0;
        if(k == 1) x = 2,y = 1;
        else for(register ll i = n;i > 2;--i){
            ll sum = (i-1)*(i-2)/2;
            if(sum < k){
                x = i;
                y = k - sum;
                break;
            }
        }
        for(register ll i = n;i > x;--i) cout << 'a';
        cout << 'b';
        for(register ll i = x-1;i > y;--i) cout << 'a';
        cout << 'b';
        for(register ll i = y-1;i >= 1;--i) cout << 'a';
        cout << "\n";
    }   

    return 0;
}

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
//int[1e7] ll[5*1e6]
typedef long long ll;
typedef unsigned long long ull;
using std::string;using std::cin;using std::cout;

inline int gcd(int x,int y){return y ? gcd(y , x % y) : x;}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    int t,ans,x;
    cin >> t;
    cin >> x;
    if(x < 0) x *= -1;
    ans = x , --t;
    while(t--){
        cin >> x;
        if(x < 0) x *= -1;
        ans = gcd(ans , x);
    }
    cout << ans;
    return 0;
}

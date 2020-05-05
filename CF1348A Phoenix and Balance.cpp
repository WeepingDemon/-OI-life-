#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<cstdlib>//rand()
#define rep(i,a,b) for(register long long i = (a);i <= (b);++i)
#define per(i,a,b) for(register long long i = (a);i >= (b);--i)
typedef long long ll;
typedef unsigned long long ull;
using std::string;using std::cin;using std::cout;

int T,n,po[33],sum[33];

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> T;
    po[1] = 2;
    sum[1] = 2;
    rep(i,2,31){
        po[i] = po[i-1] * 2;
        sum[i] = sum[i-1] + po[i];
    }
    while(T--){
        cin >> n;
        cout << 2 * (po[n] + sum[n / 2 - 1]) - sum[n] << "\n"; 
    }
    

    return 0;
}

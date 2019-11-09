#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
using std::cin;using std::cout;using std::endl;
typedef long long ll;
typedef unsigned long long ull;
ll h[2222][2222],mod,ans[2222][2222];

void yh(){
    h[0][0] = 1;
    for(int i = 1;i <= 2000;i++){
        h[i][0] = 1;
        for(int j = 1;j <= i;j++){
            h[i][j] = h[i-1][j] + h[i-1][j-1];
            h[i][j] %= mod;
            ans[i][j] = ans[i][j-1] + ans[i-1][j] - ans[i-1][j-1] + (h[i][j] == 0 ? 1 : 0);
        }
        ans[i][i+1] = ans[i][i];//防止越界
    }
    return;
}


int main(){
    // freopen("in.in", "r", stdin);

    int t;
    cin >> t >> mod;
    yh();
    while(t--){
        int a,b;
        cin >> a >> b;
        cout << ans[a][std::min(a,b)] << endl;
    }
    return 0;
}

/*题解：https://www.luogu.org/blog/Mifer/post-2019393-post (T2)*/
#include <iostream>
using std::cin;using std::cout;using std::endl;
const int mod = 1e9+7;
typedef long long ll;
ll n;

struct mat{
    ll m[5][5];
}e,base,k;

mat mul(mat x,mat y){
    mat ans = k;
    for(int i = 1;i <= 3;i++)
     for(int j = 1;j <= 3;j++)
      for(int k = 1;k <= 3;k++)
       ans.m[i][j] = ans.m[i][j] % mod + ( x.m[i][k] * y.m[k][j] ) % mod;
    return ans;
}

mat _pow(ll y){
    mat ans = e;
    mat b = base;
    while(y){
        if(y & 1) ans = mul(ans,b);
        b = mul(b,b);
        y >>= 1;
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    for(int i = 1;i <= 3;i++) e.m[i][i] = 1;
    base.m[1][1] = base.m[1][3] = base.m[2][1] = base.m[3][2] = 1;
    while(t--){
        cin >> n;
        if(n <= 3){
            cout << 1 << endl;
            continue;
        }
        mat ans = _pow(n-3);
        cout << ( ans.m[1][1] + ans.m[1][2] + ans.m[1][3] ) % mod << endl;
    }
    return 0;
}

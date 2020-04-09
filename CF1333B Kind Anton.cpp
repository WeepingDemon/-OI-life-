#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<cstdlib>//rand()
#define rep(i,a,b) for(register long long i = (a);i <= (b);++i)
#define per(i,a,b) for(register long long i = (a);i >= (b);--i)
typedef long long ll;
typedef unsigned long long ull;
using std::string;using std::cin;using std::cout;

int a[111111],b[111111],n;
bool p[111111][3],flag;

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);

    int T;
    cin >> T;
    while(T--){
        flag = true;
        cin >> n;
        rep(i,1,n) cin >> a[i];
        rep(i,1,n) cin >> b[i];
        rep(i,0,n) p[i][1] = p[i][2] = false;
        rep(i,1,n){
            p[i][1] = p[i-1][1] , p[i][2] = p[i-1][2];
            if(a[i] == 1) p[i][1] = true;
            else if(a[i] == -1) p[i][2] = true;
        }
        rep(i,1,n){
            if(b[i] == a[i]) continue;
            if(b[i] > a[i] && p[i-1][1] == false) flag = false;
            if(b[i] < a[i] && p[i-1][2] == false) flag = false;
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

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

int T,n,k,a[111],b[111],m;
bool flag[111];

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> T;
    while(T--){
        n = k = m = 0;
        cin >> n >> k;
        rep(i,1,111) flag[i] = false;
        rep(i,1,n){
            cin >> a[i];
            if(flag[ a[i] ] == false) flag[ a[i] ] = true , b[++m] = a[i];
        }
        if(m > k){
            cout << "-1\n";
            continue;
        } else {
            rep(i,m+1,k){
                b[i] = b[i-m];
            }
            cout << n * k << "\n";
            rep(i,1,n){
                rep(j,1,k){
                    cout << b[j] << " ";
                }
            }
            cout << "\n";
        }


        
    }
    

    return 0;
}

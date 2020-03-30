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

int n,T,a[55555],b[55555],x[55555];
bool flag;
char ch;

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> T;
    while(T--){
        flag = false;
        cin >> n;
        for(register int i = 1;i <= n;++i){
            cin >> ch;
            x[i] = ch - '0';
            a[i] = b[i] = 0;
        }
        a[1] = b[1] = 1;
        for(register int i = 2;i <= n;++i){
            if(!flag){
                if(x[i] == 0) continue;
                if(x[i] == 1){
                    flag = true , a[i] = 1 , b[i] = 0;
                } else {
                    flag = false , a[i] = b[i] = 1;
                }
                continue;
            }
            if(x[i] == 1) b[i] = 1;
            else if(x[i] == 2) b[i] = 2;
        }
        for(register int i = 1;i <= n;++i) cout << a[i];
        cout << "\n";
        for(register int i = 1;i <= n;++i) cout << b[i];
        cout << "\n";
    }
    

    return 0;
}

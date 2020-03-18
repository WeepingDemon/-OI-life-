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

string str;
int len,tmp,max;
bool now;

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    int T;
    cin >> T;
    while(T--){
        max = 0 , tmp = 0;
        cin >> str;
        len = str.length();
        for(register int i = 0;i < len;++i){
            if(str[i] == 'L'){
                if(now){
                    ++tmp;
                } else {
                    tmp = 1 , now = true;
                }
                continue;
            } else {
                if(now){
                    max = max > tmp ? max : tmp;
                    now = false;
                }
            }
        }
        max = max > tmp ? max : tmp;
        cout << max + 1 << "\n";
    }
    

    return 0;
}

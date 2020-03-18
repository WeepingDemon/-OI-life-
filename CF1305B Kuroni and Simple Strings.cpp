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

std::string str;
char ch[1111];
int ans[1111],p;
inline bool cmp(int x,int y){return x < y;}

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> str;
    int len = str.length();
    for(register int i = 1;i <= len;++i){
        ch[i] = str[i-1];
    }
    for(register int i = 1 , j = len;i < len;++i){
        if(j <= i) break;
        if(ch[i] == ')') continue;
        else {
            while(ch[j] == '(' && j > i) --j;
            if(j <= i) break;
            if(ch[j] == ')'){
                ans[++p] = i , ans[++p] = j--;
            }

        }
    }
    std::sort(ans+1,ans+p+1,cmp);
    if(p == 0){cout << p;return 0;}
    cout << 1 << "\n" << p << "\n";
    for(register int i = 1;i <= p;++i){
        cout << ans[i] << " ";
    }

    return 0;
}

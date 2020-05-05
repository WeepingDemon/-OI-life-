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

int n,k;
char ch[100001];

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);

    int T;
    cin >> T;
    while(T--){
        cin >> n >> k;
        rep(i,1,n) cin >> ch[i];
        std::sort(ch+1,ch+n+1);
        if(ch[1] != ch[k]) cout << ch[k] << "\n";
        else {
            if(ch[k + 1] == ch[n]){
                cout << ch[k];
                rep(i,1,(n - k) / k + ((n - k) % k == 0 ? 0 : 1)) cout << ch[i+k];
                cout << "\n";
            } else {
                rep(i,k,n) cout << ch[i];
                cout << "\n";
            }
        }

    }   

    return 0;
}

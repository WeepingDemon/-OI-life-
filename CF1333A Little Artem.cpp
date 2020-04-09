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

int t,n,m;

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);

    cin >> t;
    while(t--){
        cin >> n >> m;
        if(n % 2 && m % 2){
            rep(i,1,n-1){
                rep(j,1,m){
                    if(i % 2) cout << "B";
                    else cout << "W";
                }
                cout << "\n";
            }
            rep(i,1,m){
                if(i % 2) cout << "B";
                else cout << "W";
            }
            cout << "\n";
        } else {
            if(n % 2 == 0){
                rep(i,1,n){
                    rep(j,1,m){
                        if(i == 2 && j == 1) cout << "B";
                        else if(i % 2) cout << "B";
                        else cout << "W";
                    }
                    cout << "\n";
                }
            } else {
                rep(i,1,n){
                    rep(j,1,m){
                        if(j == 2 && i == 1) cout << "B";
                        else if(j % 2) cout << "B";
                        else cout << "W";
                    }
                    cout << "\n";
                }
            }
        }
    }

    return 0;
}

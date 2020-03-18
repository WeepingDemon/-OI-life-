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

int max,n,a[333][333];

int main(){
    //std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    
    cin >> n;
    for(register int i = 1;i <= n;++i){
      cin >> a[i][i];
      max = max > a[i][i] ? max : a[i][i];
    }
    for(register int len = 1;len < n;++len){
      for(register int i = 1;i + len <= n;++i){
        int j = i + len;
        for(register int k = i;k < j;++k){
          if(a[i][k] == a[k+1][j] && a[i][k] != 0){
            a[i][j] = a[i][k] + 1;
            max = max > a[i][j] ? max : a[i][j];
          }
        }
      }
    }
    cout << max << "\n";
    return 0;
}

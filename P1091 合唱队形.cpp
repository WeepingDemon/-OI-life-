#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;using std::endl;using std::lower_bound;
typedef long long ll;
typedef unsigned long long ull;
ll n,a[444],d[444],len,ans,tmp;
/*
思路：
枚举最高同学，进行有约束条件的两次LCS
*/
int main(){
    // freopen("in.in","r",stdin);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){//枚举最高同学
        int sta = a[i];
        len = 0;
        for(int j = 1;j < i;j++){//第一次LCS
            if(a[j] >= sta) continue;
            if(len == 0){
                d[++len] = a[j];
                continue;
            }
            if(a[j] > d[len]) d[++len] = a[j];
            else{
                int pos = lower_bound(d+1,d+len+1,a[j]) - d;
                d[pos] = a[j];
            }
        }
        tmp = len;
        len = 0;
        for(int j = n;j > i;j--){//第二次LCS
            if(a[j] >= sta) continue;
            if(len == 0){
                d[++len] = a[j];
                continue;
            }
            if(a[j] > d[len]) d[++len] = a[j];
            else{
                int pos = lower_bound(d+1,d+len+1,a[j]) - d;
                d[pos] = a[j];
            }
        }
        tmp += len;
        // cout << tmp << endl;
        ans = std::max(ans,tmp);
    }
    cout << n-ans-1;
    return 0;
}

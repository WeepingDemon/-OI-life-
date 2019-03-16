/*题解：https://www.luogu.org/blog/Mifer/st-biao*/
#include<cstdio>
#include<algorithm>
#include<cmath>
using std::max;using std::log;
int N,M,st[100005][50],a;

int main(){
    scanf("%d%d",&N,&M);
    for(int i = 1;i <= N;i++){
            scanf("%d",&a);
        st[i][0] = a;
    }
    for(int i = 1;(1 << i) <= N;i++){
        for(int j = 1;j <= N - (1 << i) + 1;j++){
            st[j][i] = max(st[j][i-1],st[j + (1 << (i - 1))][i-1]);
        }
    }
    int l,r;
    for(int i = 1;i <= M;i++){
        scanf("%d%d",&l,&r);
        int height = log(r - l + 1)/log(2);
         printf("%d\n",max(st[l][height],st[r - (1 << height) + 1][height]));
    }
    return 0;
}

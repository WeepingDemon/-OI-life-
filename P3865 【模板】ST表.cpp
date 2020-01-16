#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>

using std::cin;using std::cout;using std::endl;
typedef long long ll;
typedef unsigned long long ull;

int st[100005][50],n,m;

inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

void build(){
    for(int i = 1;i <= n;i++) st[i][0] = read();
    for(int i = 1;(1 << (i-1)) <= n;i++){
        for(int j = 1;j <= n+1-(1 << (i-1));j++) st[j][i] = std::max(st[j+(1<<(i-1))][i-1],st[j][i-1]);
    }
}

ll query(int l,int r){
    int pow = log2(r-l+1);
    int len = 1<<pow;
    return std::max(st[l][pow],st[r-len+1][pow]);
}

int main(){
    n = read() , m = read();
    build();
    int l,r;
    for(int i = 1;i <= m;i++){
        l = read() , r = read();
        printf("%lld\n",query(l,r));
    }
    
    return 0;
}

/*
实现build();和query();函数，分别用来构造st表和st查询
st表实现O(1)查询区间最大值
st[x][p]表示x~x+2^p-1内的最大值
*/

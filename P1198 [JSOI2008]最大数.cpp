//开O2 ， 单调查找改二分即可
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
//int[1e7] ll[5*1e6]
typedef long long ll;
typedef unsigned long long ull;
using std::string;using std::cin;using std::cout;

bool flg = false;
int m,p,x,tail,tmp;
char opt;

struct node{
    int num;
    int sum;
}a[200001];

inline void update(){
    if(flg == false){
        a[++tail].num = x , a[tail].sum = 1;
        return;
    }
    
    if(a[tail].num > x) a[++tail].num = x , a[tail].sum = 1;
    else{
        int tmp_sum = 1;
        while(tail >= 1 && a[tail].num <= x){
            a[tail].num = x , a[tail].sum += tmp_sum , tmp_sum = a[tail].sum , --tail;
        }
        ++tail;
    }
    return;
}

inline int query(){
    // cout << a[tail].num << "\n\n";
    for(register int i = tail;i >= 1;--i){
        if(a[i].sum < x){
            x -= a[i].sum;
        } else {
            tmp = a[i].num;
            return tmp;
        }
    }
    return 0;
}


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> m >> p;
    while(m--){
        cin >> opt >> x;
        if(opt == 'Q'){
            if(flg == false) cout << 0 << "\n"; 
            else cout << query() << "\n";
        } else {
            x = (x + tmp) % p;
            update();
            flg = true;
        }
    }
    return 0;
}

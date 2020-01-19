#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
//int[1e7] ll[5*1e6]
typedef long long ll;
typedef unsigned long long ull;
using std::cin;using std::cout;

int n,m,a[200010],opt,x,y,cnt;

struct node {
    int l,r,sum,x,tag;
    node * ls, * rs;
    inline int dis(){return r - l + 1;}
}tree[800005];

inline node * create(){return & tree[++cnt];}

inline void pushup(node * cur){
    cur->sum = cur->ls->sum + cur->rs->sum;
    return;
}

inline void pushdown(node * cur){
    cur->ls->tag ^= cur->tag;
    cur->rs->tag ^= cur->tag;
    if(cur->tag != 0) cur->ls->sum = cur->ls->dis() - cur->ls->sum;
    if(cur->tag != 0) cur->rs->sum = cur->rs->dis() - cur->rs->sum;
    cur->tag = 0;
    return;
}

inline int query(node * cur){
    if(cur->l > y || cur->r < x) return 0;
    if(cur->l >= x && cur->r <= y) return cur->sum;
    pushdown(cur);
    return query(cur->ls) + query(cur->rs);
}

inline void update(node * cur){
    if(cur->l > y || cur->r < x) return;
    if(cur->l >= x && cur->r <= y){
        cur->tag ^= 1;
        cur->sum = cur->dis() - cur->sum;
        return;
    }
    pushdown(cur);
    update(cur->ls) , update(cur->rs);
    pushup(cur);
    return;
}

inline void build(node * cur,int l,int r){
    cur->l = l , cur->r = r;
    if(l == r){
        cur->x = a[l];
        if(cur->x == 1) cur->sum = 1;
        else cur->sum = 0;
        return;
    }
    int mid = (l + r) >> 1;
    cur->ls = create() , cur->rs = create();
    build(cur->ls,l,mid) , build(cur->rs,mid+1,r);
    pushup(cur);
    return;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> n >> m;
    char ch;
    for(int i = 1;i <= n;++i){
        cin >> ch;
        a[i] = ch - '0';
    }

    node * root = create();
    build(root,1,n);

    while(m--){
        cin >> opt >> x >> y;
        if(opt == 1){
            cout << query(root) << "\n";
        } else {
            update(root);
        }
    }
    

    return 0;
}

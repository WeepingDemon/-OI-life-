#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
//int[1e7] ll[5*1e6]
typedef long long ll;
typedef unsigned long long ull;
using std::cin;using std::cout;

int n,m,a[200010],cnt,now,nown,L,R;

struct node{
    node * ls , * rs;
    int l,r,max;
}tree[400010];

inline node * create(){return & tree[++cnt];}

inline void pushup(node * cur){
    if(cur->ls->max > cur->rs->max){
        cur->max = cur->ls->max;
    } else {
        cur->max = cur->rs->max;
    }
}

inline void build(node * cur , int l , int r){
    if(l == r){
        cur->l = cur->r = l , cur->max = a[l] ;
        return;
    }
    cur->l = l , cur -> r = r;
    cur->ls = create() , cur->rs = create();
    build(cur->ls,l,(l + r) >> 1) , build(cur->rs,((l + r) >> 1 ) + 1 , r);
    pushup(cur);
    return;
}

inline int query(node * cur){
    if(cur->l > R || cur->r < L) return 0;
    if(cur->l >= L && cur->r <= R) return cur->max;
    return std::max(query(cur->ls),query(cur->rs));
}

inline void make(node * cur){
    if(cur->l == cur->r && cur->l == nown){
        cur->max = now;
        return;
    }
    if(nown < cur->l || nown > cur->r) return;
    make(cur->ls) , make(cur->rs);
    pushup(cur);
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("in.in", "r", stdin);
    cin >> n >> m;
    for(register int i = 1; i <= n;++i){
        cin >> a[i];
    }
    
    node * root = create();
    build(root,1,n);

    for(register int i = 1; i <= m;++i){
        char opt;
        cin >> opt;
        if(opt == 'Q'){
            cin >> L >> R;
            cout << query(root) << "\n";
        } else {
            cin >> nown >> now;
            if(now <= a[nown]) continue;
            else make(root);
            if(now > a[nown]) a[nown] = now;
        }
    }
    
    return 0;
}

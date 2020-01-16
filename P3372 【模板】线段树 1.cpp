#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
//int[1e7] ll[5*1e6]
typedef long long ll;
typedef unsigned long long ull;
using std::cin;using std::cout;using std::endl;

ll n,m,a[100010],L,R,cnt;

struct node{
    ll l,r,sum,tag;
    node * ls,* rs;
    ll dis(){return r - l + 1;};
}tree[400010];

node * create(){return &tree[cnt++];}

void pushup(node * cur){cur->sum = cur->ls->sum + cur->rs->sum;}

void pushdown(node * cur){
    cur->ls->tag += cur->tag;
    cur->rs->tag += cur->tag;
    cur->ls->sum += cur->tag * cur->ls->dis();
    cur->rs->sum += cur->tag * cur->rs->dis();
    cur->tag = 0;
}

void build(node *cur,ll l,ll r){
    cur->l = l , cur->r = r;
    if(l == r){cur->sum = a[l];return;}
    cur->ls = create() , cur->rs = create();
    ll mid = (l + r) >> 1;
    build(cur->ls,l,mid) , build(cur->rs,mid+1,r);
    pushup(cur);
}

ll query(node *cur){
    if(L <= cur->l && cur->r <= R) return cur->sum;
    if(cur->r < L || R < cur->l) return 0;
    pushdown(cur);
    return query(cur->ls) + query(cur->rs);
}

void update(node *cur,ll x){
    // printf("Now Updating\n");
    if(L <= cur->l && cur->r <= R){cur->sum += x * cur->dis() , cur->tag += x;return;}
    if(cur->r < L || R < cur->l) return;
    pushdown(cur);
    update(cur->ls,x) , update(cur->rs,x);
    pushup(cur);
}

int main(){
    ll x;int opt;
    scanf("%lld%lld",&n,&m);
    for(ll i = 1;i <= n;i++) scanf("%d",a+i);
    node *root = create();
    build(root,1,n);

    while(m--){
        scanf("%d%d%d",&opt,&L,&R);
        if(opt == 1){
            scanf("%lld",&x);
            update(root,x);
        }else printf("%lld\n",query(root));
    }
    return 0;
}

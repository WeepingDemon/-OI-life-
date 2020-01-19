#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
//int[1e7] ll[5*1e6]
typedef long long ll;
typedef unsigned long long ull;
using std::cin;using std::cout;

int n,cnt,x,ans,a[8005],b[8005],cnt_b;

struct node{
    int l,r;
    node * ls, * rs;
    int sum;
}tree[32005];

inline node * create(){return & tree[++cnt];}

inline void build(node * cur , int l , int r){
    cur->l = l , cur->r = r;
    if(l == r){
        cur->sum = 1;
        return;
    }
    cur->ls = create() , cur->rs = create();
    int mid = (l + r) >> 1;
    build(cur->ls,l,mid) , build(cur->rs,mid + 1,r);
    cur->sum = cur->ls->sum + cur->rs->sum;
    return;
}

inline void query(node * cur){
    
    if(cur->l == cur->r){
        ans = cur->l;
        return;
    }
    //cout << "now " << cur->l << " " << cur->r  << " " << cur->sum << " " << "\n";
    
    if(cur->sum < x) return;
    if(cur->ls->sum >= x){query(cur->ls); --cur->ls->sum;}
    else {x -= cur->ls->sum; query(cur->rs); --cur->rs->sum;}
    return;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> n;

    node * root = create();
    build(root,1,n);

    a[1] = 0;
    for(int i = 2;i <= n;++i){
        cin >> a[i];
    }

    for(int i = n;i >= 1;--i){
        x = a[i];
        ++x;
        query(root);
        --root->sum;
        b[++cnt_b] = ans;
    }
    for(int i = cnt_b;i >= 1;--i){
        cout << b[i] << "\n";
    }

    return 0;
}

#include<cstdlib>
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

int tot , inf = 1e9+9 , root;

struct node{
    int l,r,val,rnd,size,cnt;
}a[400010];

inline void New(int val){
    a[++tot].val = val;
    a[tot].size = a[tot].cnt = 1;
    a[tot].rnd = std::rand();
}

inline void Update(int p){
    a[p].size = a[ a[p].l ].size + a[ a[p].r ].size + a[p].cnt;
}

inline void build(){
    New(-inf) , New(inf);
    root = 1 , a[1].r = 2;
    Update(root);
}

inline void turnL(int & p){
    int q = a[p].r;
    a[p].r = a[q].l , a[q].l = p , p = q;
    Update(p) , Update(a[p].l);
    return;
}
inline void turnR(int & p){
    int q = a[p].l;
    a[p].l = a[q].r , a[q].r = p , p = q;
    Update(p) , Update(a[p].r);
    return;
}

inline void Insert(int & p , int val){
    if(p == 0){
        New(val);
        p = tot;
    } else if(a[p].val == val){
        ++a[p].cnt;
        Update(p);
    } else if(val < a[p].val){
        Insert(a[p].l,val);
        if(a[p].rnd < a[ a[p].l ].rnd) turnR(p);
        Update(p);
    } else if(val > a[p].val){
        Insert(a[p].r,val);
        if(a[p].rnd < a[ a[p].r ].rnd) turnL(p);
        Update(p);
    }
    return;
}

inline void Remove(int & p , int val){
    if(p == 0)return;
    if(a[p].val == val){
        if(a[p].cnt > 1){
            --a[p].cnt;
            Update(p);
        } else {
            if(a[p].l || a[p].r){
                if(a[p].r == 0 || a[ a[p].l ].rnd > a[ a[p].r ].rnd)
                    turnR(p) , Remove(a[p].r,val) , Update(p);
                else
                    turnL(p) , Remove(a[p].l,val) , Update(p);
            } else p = 0;
        }
    } else {
        val < a[p].val ? Remove(a[p].l,val) : Remove(a[p].r,val);
        Update(p);
    }
    return;
}

inline int GetRank(int p , int val){
    if(p == 0) return 0;
    if(a[p].val == val) return a[ a[p].l ].size;
    if(val < a[p].val) return GetRank(a[p].l , val);
    else return GetRank(a[p].r , val) + a[p].cnt + a[ a[p].l ].size;
}

inline int GetVal(int p , int rank){
    if(p == 0) return inf;
    if(rank <= a[ a[p].l ].size) return GetVal(a[p].l,rank);
    if(rank <= a[ a[p].l ].size + a[p].cnt) return a[p].val;
    else return GetVal(a[p].r , rank - a[p].cnt - a[ a[p].l ].size);
}

inline int GetPre(int val){
    int ans = 1 , p = root;
    while(p){
        if(val == a[p].val){
            if(a[p].l){
                p = a[p].l;
                while(a[p].r) p = a[p].r;
                ans = p;
            }
            break;
        }
        if(a[p].val < val && a[ans].val < a[p].val) ans = p;
        p = val < a[p].val ? a[p].l : a[p].r;
    }
    return a[ans].val;
}
inline int GetNext(int val){
    int ans = 2 , p = root;
    while(p){
        if(val == a[p].val){
            if(a[p].r){
                p = a[p].r;
                while(a[p].l) p = a[p].l;
                ans = p;
            }
            break;
        }
        if(a[p].val > val && a[ans].val > a[p].val) ans = p;
        p = val < a[p].val ? a[p].l : a[p].r;
    }
    return a[ans].val;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    int T,opt,x;
    cin >> T;
    build();
    while(T--){
        cin >> opt >> x;
        switch(opt){
            case 1:Insert(root,x);
            break;
            case 2:Remove(root,x);
            break;
            case 3:cout << GetRank(root,x) << "\n";
            break;
            case 4:cout << GetVal(root,x+1) << "\n";
            break;
            case 5:cout << GetPre(x) << "\n";
            break;
            case 6:cout << GetNext(x) << "\n";
            break;
        }
    }
    return 0;
}

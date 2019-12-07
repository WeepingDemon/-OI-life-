#include<iostream>
#include<cstdio>
using std::cin; using std::cout; using std::endl;
typedef long long ll;
int n,m,p,L,R,opt,cnt;
ll a[100010],k;

struct node{
	int l,r;
	node *ls,*rs;
	ll tag1,tag2,sum;
	inline ll dis(){return r - l + 1;}
}tree[400010];
//tag1 -> add  				// tag2 -> mat

inline node * create(){	return &tree[++cnt];}

inline void pushup(node * cur){	
	cur->sum = cur->ls->sum + cur->rs->sum;
}

inline void pushdown(node * cur){
//-----------------------------------------------------
	cur->ls->tag1 *= cur->tag2 , cur->ls->tag1 

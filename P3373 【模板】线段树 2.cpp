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
//tag1 -> add  	// tag2 -> mat

inline node * create(){	return &tree[++cnt]; }

inline void pushup(node * cur){	cur->sum = cur->ls->sum + cur->rs->sum; }

inline void pushdown(node * cur){
//-----------------------------------------------------
	cur->ls->tag1 *= cur->tag2 , cur->ls->tag1 %= p;
	cur->ls->tag2 *= cur->tag2 , cur->ls->tag2 %= p;
	cur->ls->sum *= cur->tag2 , cur->ls->sum %= p;
	cur->ls->tag1 += cur->tag1 , cur->ls->tag1 %= p;
	cur->ls->sum += cur->tag1 * cur->ls->dis() , cur->ls->sum %= p;
//-----------------------------------------------------
	cur->rs->tag1 *= cur->tag2 , cur->rs->tag1 %= p;
	cur->rs->tag2 *= cur->tag2 , cur->rs->tag2 %= p;
	cur->rs->sum *= cur->tag2 , cur->rs->sum %= p;
	cur->rs->tag1 += cur->tag1 , cur->rs->tag1 %= p;
	cur->rs->sum += cur->tag1 * cur->rs->dis() , cur->rs->sum %= p;
//-----------------------------------------------------
	cur->tag1 = 0 , cur->tag2 = 1;
}

inline void build(node * cur , int l , int r){
	cur->l = l , cur->r = r;
	cur->tag1 = 0 , cur->tag2 = 1;
	if(l == r){
		cur->sum = a[l] % p;
		return;
	}
	int mid = (l + r) >> 1;
	cur->ls = create() , cur->rs = create();
	build(cur->ls,l,mid) , build(cur->rs,mid+1,r);
	pushup(cur);
}

inline ll query(node * cur){
	if(R < cur->l || cur->r < L) return 0;
	if(L <= cur->l && cur->r <= R) return cur->sum % p;
	pushdown(cur);
	return ( query(cur->ls) + query(cur->rs) ) % p;
}

inline void add(node * cur){
	if(R < cur->l || cur->r < L) return;
	if(L <= cur->l && cur->r <= R){
		cur->tag1 += k , cur->sum += k * cur->dis();
		cur->tag1 %= p , cur->sum %= p;
		return;
	}
	pushdown(cur);
	add(cur->ls) , add(cur->rs);
	pushup(cur);
}

inline void mat(node * cur){
	
	if(R < cur->l || cur->r < L) return;
	if(L <= cur->l && cur->r <= R){
		cur->tag2 *= k , cur->sum *= k , cur->tag1 *= k;
		cur->tag2 %= p , cur->sum %= p , cur->tag1 %= p;
		return;
	}
	pushdown(cur);
	mat(cur->ls) , mat(cur->rs);
	pushup(cur);
}

int main(){
	std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m >> p;
	for(register int i = 1;i <= n;++i){		cin >> a[i];	}
	
	node * root;	root = create();
	build(root,1,n);
	
	for(register int i = 1;i <= m;++i){
		cin >> opt >> L >> R;
		if(opt == 3){
			cout << query(root) % p << "\n";
		} else if(opt == 1){
			cin >> k;
			mat(root);
		} else if(opt == 2){
			cin >> k;
			add(root);
		}
	}
}

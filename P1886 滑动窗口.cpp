#include<iostream>
#include<algorithm>
using std::cin;using std::cout;
typedef long long lll;
int ll,rr;

int a[1000010],n,k,cnt;

struct node{
	int l,r;
	node * ls, * rs;
	int minn,maxx;
}tree[4000010];

inline node *create(){	return &tree[++cnt];}

inline void pushup(node *cur){
	cur->minn = std::min(cur->ls->minn,cur->rs->minn);
	cur->maxx = std::max(cur->ls->maxx,cur->rs->maxx);
}

inline void build(node *cur,int L,int R){
	cur->l = L , cur->r = R;
	if(L >= R){cur->maxx = a[L] , cur->minn = a[L];return;}
	int mid = ((L + R) >> 1);
	cur->ls = create() , cur->rs = create();
	build(cur->ls,L,mid) , build(cur->rs,mid+1,R);
	pushup(cur);
}

inline int querymin(node *cur){
	if(cur->l > rr || cur->r < ll) return 1000000000;
	if(cur->l >= ll && cur->r <= rr) return cur->minn;
	return std::min(querymin(cur->ls) , querymin(cur->rs));
}

inline int querymax(node *cur){
	if(cur->l > rr || cur->r < ll) return -1000000000;
	if(cur->l >= ll && cur->r <= rr) return cur->maxx;
	return std::max(querymax(cur->ls) , querymax(cur->rs));
}

int main(){
	std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for(register int i = 1;i <= n;++i){		cin >> a[i];	}
	
	node *root = create();
	build(root,1,n);
	for(register int i = 1;i + k - 1 <= n;++i){
		ll = i , rr = i+k-1;
		cout << querymin(root) << " ";
	}
	cout << "\n";
	for(register int i = 1;i + k - 1 <= n;++i){
		ll = i , rr = i+k-1;
		cout << querymax(root) << " ";
	}
	
	
	
}

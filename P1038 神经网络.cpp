#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using std::cin;using std::cout;using std::endl;
using std::queue;
typedef long long ll;
typedef unsigned long long ull;
int n,p,C[111],U[111],cnt,top[111],cnto;
int next[111],ver[111],edge[111],deg[111],head[111];
queue<int> q;

void add(int x,int y,int z){next[++cnt] = head[x] , head[x] = cnt , ver[cnt] = y , edge[cnt] = z , ++deg[y];}

void topsort(){
	for(int i = 1;i <= n;i++) if(deg[i] == 0) q.push(i);
	while(q.size()){
		int x = q.front();    q.pop();
		for(int i = head[x];i;i = next[i]){
			int y = ver[i];
			if(C[x] > 0) C[y] += C[x]*edge[i];
			if(--deg[y] == 0) q.push(y);
		}
	}
}

int main(){
	cin >> n >> p;
	for(int i = 1;i <= n;i++){
		int a,b;
		cin >> a >> b;
		if(a == 0) C[i] = a-b;
		else{C[i] = a; }
	}
	
	for(int i = 1;i <= p;i++){
		int x,y,z;
		cin >> x >> y >> z;
		add(x,y,z);
	}
	
	topsort();
	
//	cout << cnto << endl;
	bool flag = false;
	
	for(int i = 1;i <= n;i++){
		if(!head[i] && C[i] > 0){
			cout << i << " " << C[i] << endl;
			flag = true;
		}
	}
	if(!flag) cout << "NULL";
	return 0;
}

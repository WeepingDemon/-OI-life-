#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;using std::endl;
using std::max;using std::min;
typedef long long ll;
typedef unsigned long long ull;
ll n,m,bag[32000];

struct node{
	int importance;
	int w;
	int cnt;
	int sons[4];
	bool havefather;
}item[65];

int main(){
	cin >> m >> n;
	for(int i = 1;i <= n;i++) item[i].cnt = 0;
	for(int i = 1;i <= n;i++){
		int a,b,c;
		item[i].havefather = false;
		cin >> a >> b >> c;
		item[i].importance = a*b;
		item[i].w = a;
		if(c){//附件 
			item[c].sons[++item[c].cnt] = i;
			item[i].havefather = true;
		}
	}
	for(int i = 1;i <= n;i++){
		if(item[i].havefather) continue;
		for(int j = m;j >= item[i].w;j--){
			
				//选0个配件
			bag[j] = max(bag[j-item[i].w]+item[i].importance,bag[j]);
			
			if(item[i].cnt == 1){
				//配件唯一时
				ll V = item[i].w+item[item[i].sons[1]].w;
				ll Welth = item[i].importance+item[item[i].sons[1]].importance;
				if(V <= j){
					bag[j] = max(bag[j],bag[j-V]+Welth);
				}
			}	
			if(item[i].cnt == 2){
				//配件有两个时
				ll V = item[i].w+item[item[i].sons[1]].w;
				ll Welth = item[i].importance+item[item[i].sons[1]].importance;
				if(V <= j){
					bag[j] = max(bag[j],bag[j-V]+Welth);
				}
				V = item[i].w+item[item[i].sons[2]].w;
				Welth = item[i].importance+item[item[i].sons[2]].importance;
				if(V <= j){
					bag[j] = max(bag[j],bag[j-V]+Welth);
				}
				V += item[item[i].sons[1]].w;
				Welth += item[item[i].sons[1]].importance;
				if(V <= j){
					bag[j] = max(bag[j],bag[j-V]+Welth);
				}
			}
		}
	}
	ll ans = 0;
	for(int i = 1;i <= m;i++){
		ans = max(ans,bag[i]);
	}
	cout << ans;
}

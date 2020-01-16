#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;using std::endl;using std::max;
typedef long long ll;
typedef unsigned long long ull;
int n;
bool havefather[6010];
struct node{
	int happy_point;
	int sons[6010];	
	int cnt;
}a[6010];
ll dp[6010][2];//dp[x][1]参加//dp[x][0]不参加 

//dp[i][1] = max{dp[sonofi][0]
void DP(int root){//flag表示其上司是否去
	ll tmp = 0;
	
	dp[root][0] = 0;
	dp[root][1] = a[root].happy_point;
	
	for(int i = 1;i <= a[root].cnt;i++){
		int sn = a[root].sons[i];
		DP(a[root].sons[i]);
		dp[root][1] += dp[sn][0];
		dp[root][0] += max(dp[sn][1],dp[sn][0]);
	}
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].happy_point;
		a[i].cnt = 0;
	}
	for(int i = 1;i < n;i++){
		int x,y;//xson,yfather
		cin >> x >> y;
		a[y].sons[++a[y].cnt] = x;
		havefather[x] = true;
	}
	int root;
	for(int i = 1;i <= n;i++){
		if(!havefather[i]){
			root = i;
			break;
		}
	}
	DP(root);
	cout << max(dp[root][1],dp[root][0]);
	return 0;
}

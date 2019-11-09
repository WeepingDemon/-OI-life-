#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;using std::endl;
typedef long long ll;
typedef unsigned long long ull;
int dp[1010],c[1010],w[101][1010],v[101][1010];
//w是weight,v是value 
int m,n;
int main(){
	cin >> m >> n;
	for(int i = 1;i <= n;i++){
		int a,b,x;
		cin >> a >> b >> x;
		w[x][++c[x]] = a;
		v[x][c[x]] = b;
	}
	for(int i = 1;i <= n;i++){
		for(int j = m;j >= 0;j--){
			for(int k = 1;k <= c[i];k++){
				if(j - w[i][k] < 0) continue;
				dp[j] = dp[j] > dp[j - w[i][k]] + v[i][k] ? dp[j] : dp[j - w[i][k]] + v[i][k];
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= m;i++){
		ans = ans > dp[i] ? ans : dp[i];
	}
	cout << ans;
	return 0;
}

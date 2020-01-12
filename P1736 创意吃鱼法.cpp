#include<iostream>
#include<cstdio>
#include<algorithm>
typedef long long ll;
using std::cin;using std::cout;using std::max;using std::min;

int m,n,dp[2505][2505],kl[2505][2505],ku[2505][2505],ans;
bool map[2505][2505];

int main(){
	std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(register int i = 1;i <= n;++i){
		for(register int j = 1;j <= m;++j){
			cin >> map[i][j];
		}
	}
	
	//1,1 to n,m
	for(register int i = 1;i <= n;++i){
		for(register int j = 1;j <= m;++j){
			
			if(!map[i][j]){
				kl[i][j] = kl[i][j-1] + 1;
				ku[i][j] = ku[i-1][j] + 1;
			} else {
				dp[i][j] = min(dp[i-1][j-1],min(kl[i][j-1],ku[i-1][j])) + 1;
				ans = ans > dp[i][j] ? ans : dp[i][j];
			}
		}
	}

	for(register int i = 1;i <= n;++i)
	 for(register int j = 1;j <= m;++j)
	  dp[i][j] = kl[i][j] = ku[i][j] = 0;
	
	//1,m to n,1
	for(register int i = 1;i <= n;++i){
		for(register int j = m;j >= 1;--j){
			
			if(!map[i][j]){
				kl[i][j] = kl[i][j+1] + 1;
				ku[i][j] = ku[i-1][j] + 1;
			} else {
				dp[i][j] = min(dp[i-1][j+1],min(kl[i][j+1],ku[i-1][j])) + 1;
				ans = ans > dp[i][j] ? ans : dp[i][j];
			}
		}
	}
	
	cout << ans;
	return 0;
}

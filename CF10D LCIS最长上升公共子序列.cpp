#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;using std::endl;
typedef long long ll;
typedef unsigned long long ull;
int dp[5010][5010],n,m,turn[5010][5010],Aj = 0;
int a[5010],b[5010];

void COUT(int i,int j){
	if(i == 0) return;
	COUT(i-1,turn[i][j]);
	if(turn[i][j] == j) return;
	cout << a[i] << " ";
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;++i) cin >> a[i];
	cin >> m;
	for(int i = 1;i <= m;++i) cin >> b[i];
	//以a为基准 
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= m;++j){
			if(a[i] == b[j]){
				for(int k = 0;k < j;k++){
					if(b[k] >= b[j]) continue;
					if(dp[i][j] > dp[i-1][k]+1) continue;
					else{
						dp[i][j] = dp[i-1][k]+1;
						turn[i][j] = k;//序列前驱下标为k 
					}
				}
			}else{
				dp[i][j] = dp[i-1][j];
				turn[i][j] = j;//序列无转移即无前驱 
			}
//			cout << dp[i][j] << " ";
		}
//		cout << endl;
	}
	cout << dp[n][m] << endl;
	Aj = 1;
	for(int i = 1;i <= m;i++){
		Aj = dp[n][Aj] > dp[n][i] ? Aj : i;
	}
	COUT(n,Aj);
	return 0;
}

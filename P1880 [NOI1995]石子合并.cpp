#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;using std::endl;using std::min;using std::max;
typedef long long ll;
typedef unsigned long long ull;
ll dp[205][205],dp_[205][205],n,a[205],sum[205];
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		a[i+n] = a[i];
		sum[i] = sum[i-1] + a[i];
	}
	for(int i = 1;i <= n;i++){
		sum[i+n] = sum[i+n-1] + a[i];
	}
	for(int len = 1;len <= n;len++){
		for(int i = 1;i+len <= 2*n;i++){
			dp[i][i+len] = 1e9+7;
			for(int k = 0;k < len;k++){
				dp[i][i+len] = min(dp[i][i+len],dp[i][i+k]+dp[i+k+1][i+len]);
				dp_[i][i+len] = max(dp_[i][i+len],dp_[i][i+k]+dp_[i+k+1][i+len]);
			}
			dp[i][i+len] += sum[i+len] - sum[i-1];
			dp_[i][i+len] += sum[i+len] - sum[i-1];
		}
	}
	ll MIN=100000,MAX=0;
	/*
	for(int i = 1;i <= 2*n;i++){
		for(int j = 1;j <= 2*n;j++){
			cout << dp[i][j] <<" ";
		}
		cout << endl;
	}
	*/
	for(int i = 1;i <= n;i++){
		MIN=min(MIN,dp[i][i+n-1]);
		MAX=max(MAX,dp_[i][i+n-1]);
	}
	cout << MIN << "\n" << MAX;
	return 0;
}

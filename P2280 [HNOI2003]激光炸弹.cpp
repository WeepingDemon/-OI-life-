#include<iostream>
#include<cstdio>
typedef long long ll;
using std::cin;using std::cout;

int r,n,x,y,v,mx,my,sum[5002][5002],ans;

int main(){
	std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> r;
	for(register int i = 1;i <= n;++i){
		cin >> x >> y >> v;
		++x , ++y;
		sum[x][y] = v;
		mx = mx > x ? mx : x;
		my = my > y ? my : y;
	}
	for(register int i = 1;i <= 5000;++i){
		for(register int j = 1;j <= 5000;++j){
			sum[i][j] = sum[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
	for(register int i = r ;i <= 5000;++i){
		for(register int j = r ;j <= 5000;++j){
			ans = ans > sum[j][i] - sum[j-r][i] - sum[j][i-r] + sum[j-r][i-r] ? ans : sum[j][i] - sum[j-r][i] - sum[j][i-r] + sum[j-r][i-r]; 
		}
	}
	cout << ans;
	return 0;
}




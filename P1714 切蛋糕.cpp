#include<iostream>
#include<cstdio>
typedef long long ll;
using std::cin;using std::cout;

int m,n,l,r;
ll a[500005],p[500005],ans;

int main(){
	std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(register int i = 1;i <= n;++i){
		int x;
		cin >> x;
		a[i] = a[i-1] + x;
	}
	l = 1 , r = 1 , ans = 0;
	for(register int i = 1;i <= n;i++){
		ans = ans > a[i] - a[p[l]] ? ans : a[i] - a[p[l]];
		while(p[l] < i - m + 1) ++l;
		while(a[p[r]] >= a[i] && r >= l) --r;
		p[++r] = i;
	}
	cout << ans;	
}

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;using std::endl;
typedef long long ll;
typedef unsigned long long ull;
int main(){
	ll n,a,b,r,x,y,sum,ans = 0;
	cin >> n >> a >> b >> r;
	r *= r;
	for(ll i = 1;i <= n;i++){
		cin >> x >> y;
		sum = (x-a) * (x-a) + (y-b) * (y-b);
		if(sum <= r) ++ans;
	}
	cout << ans;
}

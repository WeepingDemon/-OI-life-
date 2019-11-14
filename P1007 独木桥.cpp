#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;using std::endl;
typedef long long ll;
typedef unsigned long long ull;
int l,n,max,min; 
int main(){
	cin >> l >> n;
	for(int i = 1;i <= n;i++){
		int x;cin >> x;
		max = max >= x ? max : x;
		max = max >= (l-x+1) ? max : (l-x+1);
		int MIN;
		MIN = (l-x+1) < x ? (l-x+1) : x;
		min = min >= MIN ? min : MIN;
	}
	cout << min << " " << max;
	return 0;
}

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;using std::endl;using std::lower_bound;
typedef long long ll;
typedef unsigned long long ull;

int a[100010],b[100010],map[100010],d[100010],len = 1;

int main(){
	ll n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		map[a[i]] = i;
		a[i] = i; 
	}
	for(int i = 1;i <= n;i++){
		cin >> b[i];
		b[i] = map[b[i]];
	}
	d[1] = b[1];
	for(int i = 2;i <= n;i++){
		if(b[i] > d[len]) d[++len] = b[i];
		else {
			int pos = lower_bound(d+1,d+len+1,b[i]) - d;
			d[pos] = b[i];
		}
	}
	cout << len;
	return 0;
}

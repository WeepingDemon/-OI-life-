#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
typedef unsigned long long ll;

ll k,base;
int n,ans[180];

int main(){
	std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    k ^= (k >> 1);
    for(int i = n - 1;i >= 0;i--){
		cout << ((k >> i) & 1);
    }
}

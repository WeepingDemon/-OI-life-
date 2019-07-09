/*
问题是ax ≡ 1 (mod b)的最小正整数解x
实际上就是求方程ax + by = 1的解(x,y)
a ⊥ b，所以gcd(x,y) = 1
所以直接用exgcd求解并输出x的最小正整结果就行
*/


#include<iostream>
using namespace std;
#define pr pair<int,int>
#define x tmp.first
#define y tmp.second

pr exgcd(int a,int b){
	if(b == 0) return pr(1,0);
	pr tmp = exgcd(b,a%b);
	return pr(y,x - a / b * y);
}

int main(){
	int a,b;
	cin >> a >> b;
	pr tmp = exgcd(a,b);
	x = (x % b + b) % b; 
	cout << x;
}

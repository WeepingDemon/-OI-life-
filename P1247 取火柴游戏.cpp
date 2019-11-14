#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long k,n[500010],p,flag/*,AFKEA*/,ansi,ansj;
int main(){
	cin >> k;
	for(int i = 1;i <= k;i++){
		cin  >> n[i];
		p = p ^ n[i];
	}
	if(p == 0) cout << "lose";
	else{
		for(int i = 1;i <= k;i++){
			if(n[i] > (n[i]^p)){
				ansj = n[i] - (n[i]^p);
				ansi = i;
				break;
			}
		}
		cout << ansj << " " << ansi << endl;
		n[ansi] -= ansj;
		for(int i = 1;i <= k;i++){
			cout << n[i] << " ";
		}
	}
		
}

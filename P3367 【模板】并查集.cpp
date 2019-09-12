#include<iostream>
using namespace std;
int N,M,a[10001],op,x,y;

int getfa(int step){
	if(a[step] == step) return step;
	else a[step] = getfa(a[step]);
	return a[step];
}

int main(){
	cin >> N >> M;
	for(int i = 1;i <= N;i++) a[i] = i;
	for(int i = 1;i <= M;i++){
		cin >> op >> x >> y;
		if(op == 1) a[getfa(x)] = a[getfa(y)];
		else if(op == 2)
		 if(a[getfa(x)] == a[getfa(y)]) cout << "Y" << endl;
		 else cout << "N" << endl;
	}
	return 0;
}

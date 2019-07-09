#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int M,N,K,L,D,cnty,cntx,MAXx,MAXy,x[100010],y[100010];


struct node{
	int times;
	int num;
}ansx[100010],ansy[100010];

bool cmp(node a , node b){
	return a.times > b.times;
}

bool Cmp(int x,int y){
	return x < y;
}

int main(){
	cin >> M >> N >> K >> L >> D;
	for(int i = 1;i <= D;i++){
		int x,y,p,q;
		cin >> x >> y >> p >> q;
		if(x == p) ansy[min(y,q)].times ++ , MAXy = max(MAXy,q) , ansy[min(y,q)].num = min(y,q);//因为取的是最小值作为基准所以这里是哪个都可以 
		else if( y == q) ansx[min(x,p)].times ++ , MAXx = max(MAXx,x) , ansx[min(x,p)].num = min(x,p);
	} 
	sort(ansx+1,ansx+1+100010,cmp);
	sort(ansy+1,ansy+1+100010,cmp);
	cntx = 0;
	cnty = 0;
	
	for(int i = 1;i<= K;i++) x[++cntx] = ansx[i].num;
	for(int i = 1;i<= L;i++) y[++cnty] = ansy[i].num;
	
	sort(x+1,x+1+cntx,Cmp);
	sort(y+1,y+1+cnty,Cmp);
	
	for(int i = 1;i< cntx;i++) cout << x[i] << " ";
	cout << x[K] << endl;
	for(int i = 1;i< cnty;i++) cout << y[i] << " ";
	cout << y[L] << endl;
	
	return 0;
}

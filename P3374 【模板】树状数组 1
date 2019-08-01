#include<iostream>
using std::cin;using std::cout;using std::endl;using std::cerr;
int tree[2000010],N,M;
int lowbit(int x){
	return x & -x;
}

void add(int index,int k){
	while(index<=N){
		tree[index]+=k;
		index+=lowbit(index);
	}
	return;
}

int sum(int index){
	int ans=0;
	while(index!=0){
		ans+=tree[index];
		index-=lowbit(index); 
	}
	return ans;
}

int main(){
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		//cerr<<"Now beginning add"<<endl;
		int l;
		cin>>l;
		add(i,l);
	}
	//cerr<<"add end"<<endl;
	int method,a,b;
	for(int i=1;i<=M;i++){
		//cerr<<"come on"<<endl;
		cin>>method>>a>>b;
		if(method==1) add(a,b);
		if(method==2) cout<<sum(b)-sum(a-1)<<endl;
	}
	return 0;
}  

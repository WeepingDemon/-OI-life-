#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int F(int x){
	int num=0;
	int f[10] = {6,2,5,5,4,5,6,3,7,6};
	if(x==0){return 6;
	} 

	for(1;x!=0;x/=10){
		num+=f[x%10];
	}
	return num;
}

struct chain{
	int dataa;
	int datab;
	int datac;
	chain *next;
};

int main(){
	int sum=0;
	int k;
	//cout << "请输入火柴数量（不大于24,不小于10的正整数）___\b\b";
	cin >> k; 
	chain *head,*q,*p,*t;
	head=NULL;
	for(int a=0;a<1111;a++){
		for(int b=0;b<1111;b++){
			int c;
			c=a+b;
			if((F(a)+F(b)+F(c))==(k-4)) {
				sum++;
			//	cout << F(a)<< " " <<F(b)<<" "<<F(c)<<"\n";
			//	cout << a<< " " <<b<<" "<<c;
			//	getchar();
				p=(chain *)malloc(sizeof(chain));
				p->dataa=a;
				p->datab=b;
				p->datac=c;
				p->next=NULL;
				if(head==NULL){
					head=p;
				}else{
					q->next=p;
				}
				q=p;
			}
			
		}
	}
	cout /*<< "可行的方案一共有" */<< sum /*<< "种\n"*/;
	
	
}

//核心思想是归并排序，通过分治保证num[p]~num[mid]内的元素按照升序排序，并与num[mid+1]~num[q]内的元素进行归并
#include<iostream>
#include<cstdio>
using namespace std;
long long n,num[500010],ans,x[500010];

void solve(int p,int q){
	if(p == q) return; //分治到最小单元
	int mid = (p + q) / 2 , i = p , j = mid + 1 , cnt = p; 
	solve(p,mid) , solve(mid + 1,q); //分治
	while(i <= mid && j <= q){
		if(num[i] <= num[j]){
			x[cnt++] = num[i++];//如果不满足逆序对需求，则将num[i]存入x[cnt]，x[cnt]表示p~q的升序排列
		}else{
			x[cnt++] = num[j++] , ans += mid - i + 1;//如果满足逆序对需求，进行答案统计，由于num[i+1]~num[mid]都比num[i]大，所以对于num[j]都满足，将num[j]存入x[cnt]
		}
	}
  
	while(i <= mid){
		x[cnt++] = num[i++];
	}
	while(j <= q){
		x[cnt++] = num[j++];
	}//上面两个循环是为了将剩余的元素处理掉
  
	for(int t = p;t <= q;t++){
	num[t] = x[t]; 
	} //将x[t]中排序完的元素载入num
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		scanf("%lld",&num[i]);
	}
	solve(1,n);
	printf("%lld",ans);
}
